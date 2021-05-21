cmake_minimum_required(VERSION 3.19)
project(lab_03)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_PREFIX_PATH "/Users/kate/Qt/6.0.2/clang_64/lib/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(${PROJECT_NAME} main.cpp Controller/Controller.cpp
        Model/Loader/FileSceneLoader.cpp
        Model/Loader/FileModelLoader.cpp
        Model/Loader/FileCameraLoader.cpp
        Model/Containers/matrix/matrix/matrix_base.cpp
        Model/Containers/matrix/errors/errors.cpp
        Drawer/BaseDrawer.cpp
        Drawer/DrawerFactory/QtDrawerCreator.cpp
        Drawer/QtDrawer.cpp
        Model/Figure/Primitives/Edge/Edge.cpp
        Model/Figure/Primitives/Point/Point.cpp
        Model/Facade/Facade.cpp
        Model/Figure/BaseObject.cpp
        Model/Figure/CompositeObject/CompositeObject.cpp
        Model/Figure/InvisibleObject/Camera/BaseCamera.cpp
        Model/Figure/InvisibleObject/Camera/Camera.cpp
        Model/Figure/InvisibleObject/InvisibleObject.cpp
        Model/Figure/ObjectFactory/ObjectFactory.cpp
        Model/Figure/VisibleObject/FrameModel/FrameModel.cpp
        Model/Figure/VisibleObject/FrameModel/FrameModelBuilder/FrameModelBuilder.cpp
        Model/Figure/VisibleObject/FrameModel/FrameModelBuilder/FrameModelDirector.cpp
        Model/Figure/VisibleObject/VisibleObject.cpp
        Model/Handlers/BaseHandler.cpp
        Model/Handlers/LoadHandler.cpp
        Model/Handlers/MoveCameraHandler.cpp
        Model/Handlers/MoveObjectHandler.cpp
        Model/Handlers/RotateCameraHandler.cpp
        Model/Handlers/RotateObjectHandler.cpp
        Model/Handlers/ScaleObjectHandler.cpp
        Model/Scene/BaseScene.cpp
        Model/Scene/Scene.cpp
        Model/Scene/SceneBuilder/SceneBuilder.cpp
        Model/Scene/SceneBuilder/SceneDirector.cpp
        Model/Visitors/TransformObjectVisitor.cpp
        Model/Commands/MoveCameraCommand.cpp
        Model/Commands/MoveObjectCommand.cpp
        Model/Commands/RotateCameraCommand.cpp
        Model/Commands/RotateObjectCommand.cpp
        Model/Commands/ScaleObjectCommand.cpp
        Model/Commands/UndoCommand.cpp
        Model/Commands/LoadCommand.cpp
        Model/Commands/DrawCommand.cpp
        main.cpp
        View/view.cpp Model/Handlers/DrawHandler.cpp Model/Handlers/DrawHandler.h Model/Visitors/DrawObjectVisitor.cpp Model/Visitors/DrawObjectVisitor.h Model/Visitors/ProjectionVisitor.cpp Model/Visitors/ProjectionVisitor.h Model/Handlers/ProjectionHandler.cpp Model/Handlers/ProjectionHandler.h Model/Visitors/MoveObjectVisitor.cpp Model/Visitors/MoveObjectVisitor.h Model/Snapshots/Snapshot.cpp Model/Snapshots/Snapshot.h Model/Snapshots/Caretaker.cpp Model/Snapshots/Caretaker.h Model/Loader/BaseModelLoader.h Model/Solution/GraphicsSolution.cpp Model/Solution/GraphicsSolution.h Model/Solution/LoaderSolution.cpp Model/Solution/LoaderSolution.h Model/Solution/Configuration.cpp Model/Solution/Configuration.h Model/Loader/LoaderCreator/BaseLoaderCreator.h Model/Loader/LoaderCreator/FileLoaderCreator.cpp Model/Loader/LoaderCreator/FileLoaderCreator.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
