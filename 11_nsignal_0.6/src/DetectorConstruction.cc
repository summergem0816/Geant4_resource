#include <G4SubtractionSolid.hh>
#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4Material.hh"

#include "G4Element.hh"
#include "G4Isotope.hh"

#include "G4Tubs.hh"

#include "G4PVReplica.hh"
#include "G4GlobalMagFieldMessenger.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"

#include "G4SDChargedFilter.hh"
#include "G4MultiFunctionalDetector.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4UserLimits.hh"

#include "CADMesh.hh"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "G4TessellatedSolid.hh"
#include "G4TriangularFacet.hh"


#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

#include "G4AffineTransform.hh"



G4TessellatedSolid* CreateSolidFromSTL(const std::string& filename, double scaleFactor) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filename, aiProcess_Triangulate);

    if (!scene || !scene->HasMeshes()) {
        G4cerr << "Error reading STL file: " << filename << G4endl;
        return nullptr;
    }

    G4TessellatedSolid* tessellatedSolid = new G4TessellatedSolid("ImportedSTL");

    // 假设只读取第一个网格
    const aiMesh* mesh = scene->mMeshes[0];
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        const aiFace& face = mesh->mFaces[i];
        if (face.mNumIndices == 3) { // 确保是三角形面
            G4ThreeVector v1(mesh->mVertices[face.mIndices[0]].x * scaleFactor,
                             mesh->mVertices[face.mIndices[0]].y * scaleFactor,
                             mesh->mVertices[face.mIndices[0]].z * scaleFactor);
            G4ThreeVector v2(mesh->mVertices[face.mIndices[1]].x * scaleFactor,
                             mesh->mVertices[face.mIndices[1]].y * scaleFactor,
                             mesh->mVertices[face.mIndices[1]].z * scaleFactor);
            G4ThreeVector v3(mesh->mVertices[face.mIndices[2]].x * scaleFactor,
                             mesh->mVertices[face.mIndices[2]].y * scaleFactor,
                             mesh->mVertices[face.mIndices[2]].z * scaleFactor);

            G4TriangularFacet* facet = new G4TriangularFacet(v1, v2, v3, ABSOLUTE);
            tessellatedSolid->AddFacet(facet);
        }
    }

    tessellatedSolid->SetSolidClosed(true);
    return tessellatedSolid;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4TessellatedSolid* CreateScaledSolidFromSTL(const std::string& filePath, double scaleFactor)
{

    G4TessellatedSolid* tessellatedSolid = new G4TessellatedSolid("STLSolid");

    std::ifstream stlFile(filePath);
    if (!stlFile)
    {
        G4cerr << "Error: Could not open STL file " << filePath << G4endl;
        return nullptr;
    }

    std::string line;
    while (std::getline(stlFile, line))
    {
        std::istringstream iss(line);
        std::string word;
        iss >> word;
        if (word == "facet")
        {
            G4ThreeVector v1, v2, v3;
            for (int i = 0; i < 3; ++i)
            {
                std::getline(stlFile, line);
                std::istringstream vertexLine(line);
                std::string vertexWord;
                double x, y, z;
                vertexLine >> vertexWord >> x >> y >> z;
                G4ThreeVector vertex(x * scaleFactor, y * scaleFactor, z * scaleFactor);
                if (i == 0) v1 = vertex;
                if (i == 1) v2 = vertex;
                if (i == 2) v3 = vertex;
            }
            tessellatedSolid->AddFacet(new G4TriangularFacet(v1, v2, v3, ABSOLUTE));
        }
    }

    tessellatedSolid->SetSolidClosed(true);
    return tessellatedSolid;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
        : G4VUserDetectorConstruction(),
          fCheckOverlaps(true),
          fStepLimit(nullptr)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{  delete fStepLimit;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4String name;
    G4double a,density;
    G4int iz,n,z;
    G4int ncomponents,nAtoms;
    G4double abundance,pressure,temperature;

    G4Element* H  = new G4Element("Hydrogen" ,"H" , z= 1., a=   1.01*g/mole);
    G4Element* C  = new G4Element("Carbon"   ,"C" , z= 6., a=  12.01*g/mole);
    G4Element* B  = new G4Element("Boron"   ,"B" , z= 5., a=  10.81*g/mole);
    G4Element* O  = new G4Element("Oxygen" ,"O" , z= 8., a=   16.00*g/mole);
    G4Element* Gd  = new G4Element("Gadolinium" ,"Gd" , z= 64., a=   157.25*g/mole);
    G4Element* Fe  = new G4Element("Ferrum" ,"Fe" , z= 26., a=   55.85*g/mole);
    G4Element* Si  = new G4Element("Silicon" ,"Si" , z= 14., a=   28.085*g/mole);
    G4Element* La = new G4Element("Lanthanum", "La", 57., 138.90547*g/mole);
    G4Element* Ce = new G4Element("Cerium", "Ce", 58., 140.116*g/mole);


    density=1.05*g/cm3;
    G4Material*PE=new G4Material(name="polystyrene",density,ncomponents=2);
    PE->AddElement(H,8);
    PE->AddElement(C,8);

    G4Material* La2O3 = new G4Material("LanthanumOxide", 6.51*g/cm3, 2);
    La2O3->AddElement(La, 2);
    La2O3->AddElement(O, 3);

    G4double fractionMassLa2O3 = 0.99;
    G4double fractionMassCe = 0.01;

    G4Material* La2O3_Ce = new G4Material("LanthanumOxideCerium", 6.51*g/cm3, 2);
    La2O3_Ce->AddMaterial(La2O3, fractionMassLa2O3);
    La2O3_Ce->AddElement(Ce, fractionMassCe);

    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* Al = nistManager->FindOrBuildMaterial("G4_Al");
    G4Material* Air = nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* SI = nistManager->FindOrBuildMaterial("G4_Si");
    G4Material* FE = nistManager->FindOrBuildMaterial("G4_Fe");
    G4Element* elC = nistManager->FindOrBuildElement("C");
    G4Element* elF = nistManager->FindOrBuildElement("F");
    G4double mRmax=100*cm;
    

    auto worldSizeXY = 4.* mRmax;
    auto worldSizeZ=4.*mRmax;

    G4double pRMin=0.;
    G4double Scintlength=0.3*mm;//闪烁体单元边长的一半
    G4double pDz=20*mm;//闪烁体厚度的一半
    G4double Z=pDz;
    G4double pSPhi=0;
    G4double pDPhi=360*degree;
 
    G4double thick=0.030*mm;//反射层厚度
    G4double absothick=0.020*mm;//SiPM厚度的一半
    G4double pRMax=Scintlength+thick;
    int Eline=338,Erow=338;//行、列 ,SteppingAction HistoMananger EventAction.cc.hh文件对应位置也要修改
    G4double yuliang=0.020*mm;
    G4int nofScintiallator=Eline*Erow;
    // Get materials
    auto defaultMaterial = G4Material::GetMaterial("G4_AIR");
    auto moderatorMaterial = G4Material::GetMaterial("polystyrene");
    // auto moderatorMaterial = G4Material::GetMaterial("LanthanumOxideCerium");    
    auto ReflexMaterial = G4Material::GetMaterial("G4_Al");
//    auto ReflexMaterial = G4Material::GetMaterial("PTFE");
    auto AbsorberMaterial = G4Material::GetMaterial("G4_Si");
    auto AimMaterial = G4Material::GetMaterial("G4_Fe");
  
    // World
    //
    auto worldS
            = new G4Box("World",           // its name
                        worldSizeXY/2, worldSizeXY/2, worldSizeZ/2); // its size

    auto worldLV
            = new G4LogicalVolume(
                    worldS,           // its solid
                    defaultMaterial,  // its material
                    "World");         // its name

    auto worldPV
            = new G4PVPlacement(
                    0,                // no rotation
                    G4ThreeVector(),  // at (0,0,0)
                    worldLV,          // its logical volume
                    "World",          // its name
                    0,                // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    fCheckOverlaps);  // checking overlaps


    //闪烁体阵列
  
    //闪烁体单元

    //moderator
    auto moderator
            = new G4Box("moderator",
                        Scintlength,
                         Scintlength,
                         pDz
                         );

    auto moderatorLV
            = new G4LogicalVolume(
                    moderator,           // its solid
                    moderatorMaterial,  // its material
                    "moderator");         // its name

    for(int copyNb=0;copyNb<nofScintiallator;copyNb++)
    {
        G4int line=copyNb/Eline;
        G4int row=copyNb%Erow;
        G4double Px=-(Eline)*pRMax+row*2*pRMax;
        G4double Py=-(Erow)*pRMax+line*2*pRMax;
        new G4PVPlacement(
                0,                // no rotation
                G4ThreeVector(Px,Py,0),  // at (0,0,0)
                moderatorLV,          // its logical volume
                "moderator",    // its name
                worldLV,          // its mother  volume
                false,            // no boolean operation
                copyNb,                // copy number
                fCheckOverlaps);  // checking overlaps
    }


   //Reflex 反射层
    auto Reflex0
            = new G4Box("Reflex0",
                         pRMax,
                         pRMax,
                         pDz);// its size
    auto Reflex1
            = new G4Box("Reflex1",
                        Scintlength,
                        Scintlength,
                         pDz);
    G4SubtractionSolid* Reflex =
            new G4SubtractionSolid("Reflex0-Reflex1", Reflex0, Reflex1);

    auto ReflexLV
            = new G4LogicalVolume(
                    Reflex,           // its solid
                    defaultMaterial,  // its material
                    "Reflex");         // its name


    //line2 row3代表第二行第三列
    for(int copyNb=0;copyNb<nofScintiallator;copyNb++)
    {
        G4int line=copyNb/Eline;
        G4int row=copyNb%Erow;
        G4double Px=-(Eline)*pRMax+row*2*pRMax;
        G4double Py=-(Erow)*pRMax+line*2*pRMax;
        new G4PVPlacement(
                0,                // no rotation
                G4ThreeVector(Px, Py, 0),
                ReflexLV,          // its logical volume
                "Reflex",    // its name
                worldLV,          // its mother  volume
                false,            // no boolean operation
                copyNb,                // copy number
                fCheckOverlaps);  // checking overlaps
    }


    //
    //Abso
    auto Abso
            = new G4Box("Abso",
                        pRMax,
                         pRMax,
                         absothick);// its size

    auto AbsoLV
            = new G4LogicalVolume(
                    Abso,           // its solid
                    AbsorberMaterial,  // its material
                    "AbsoLV");         // its name

    //line2 row3代表第二行第三列
    for(int copyNb=0;copyNb<nofScintiallator;copyNb++)
    {
        G4int line=copyNb/Eline;
        G4int row=copyNb%Erow;
        G4double Px=-(Eline)*pRMax+row*2*pRMax;
        G4double Py=-(Erow)*pRMax+line*2*pRMax;
        new G4PVPlacement(
                0,                // no rotation
                G4ThreeVector(Px, Py, -Z-absothick),
                AbsoLV,          // its logical volume
                "Abso",    // its name
                worldLV,          // its mother  volume
                false,            // no boolean operation
                copyNb,                // copy number
                fCheckOverlaps);  // checking overlaps

        new G4PVPlacement(
                0,                // no rotation
                G4ThreeVector(Px, Py, Z+absothick),
                AbsoLV,          // its logical volume
                "Abso",    // its name
                worldLV,          // its mother  volume
                false,            // no boolean operation
                copyNb,                // copy number
                fCheckOverlaps);  // checking overlaps
    }

   auto test = CADMesh::TessellatedMesh::FromSTL("/nc1test1/zxr/model/z3/z53_ascii.stl");
   
   test->SetScale(5);					
   test->SetOffset(0,0,0);				
   //引入logicalvolume，设置材料
   auto logicaltest = new G4LogicalVolume( test->GetSolid(),
                                           nistManager->FindOrBuildMaterial("G4_Al") ,
                                           "logical"
                                            , 0, 0, 0);
   //创建旋转矩阵
   G4RotationMatrix* rotationMatrix=new G4RotationMatrix();
   rotationMatrix->rotateY(90.0 * deg);

    new G4PVPlacement( rotationMatrix
                     , G4ThreeVector(80*mm, -80*mm, 50*mm)
                     , logicaltest
                     , "test"
                     , worldLV
                     , false, 0);

//////////////////////////////////////////////////////////////////////////
 
    //设置颜色
    //闪烁体
    auto Red= new G4VisAttributes(G4Colour(0.6,0.4,0.2));
    Red->SetVisibility(true);
    AbsoLV->SetVisAttributes(Red);
    //反射层
    auto Blue= new G4VisAttributes(G4Colour(0.2,0.4,0.6));
    Blue->SetVisibility(true);
    ReflexLV->SetVisAttributes(Blue);


  
    // Visualization attributes
    worldLV->SetVisAttributes (G4VisAttributes::GetInvisible());
   
    return worldPV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
