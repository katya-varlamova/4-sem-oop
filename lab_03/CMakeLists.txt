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
        Model/Containers/matrix/matrix/matrix_base.cpp
        Model/Containers/matrix/errors/errors.cpp
        Drawer/BaseDrawer.cpp
        Drawer/DrawerFactory/BaseDrawerFactory.cpp
        Drawer/DrawerFactory/QtDrawerFactory.cpp
        Drawer/QtDrawer.cpp
        Model/Facade/Facade.cpp
        Model/Figure/BaseObject.cpp
        Model/Figure/VisibleObject/CompositeObject/CompositeObject.cpp
        Model/Figure/VisibleObject/Edge/BaseEdge.cpp
        Model/Figure/VisibleObject/Edge/Edge.cpp
        Model/Figure/InvisibleObject/Camera/BaseCamera.cpp
        Model/Figure/InvisibleObject/Camera/Camera.cpp
        Model/Figure/InvisibleObject/InvisibleObject.cpp
        Model/Figure/ObjectFactory/ObjectFactory.cpp
        Model/Figure/VisibleObject/Point/BasePoint.cpp
        Model/Figure/VisibleObject/Point/Point.cpp
        Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.cpp
        Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModelBuilder/FrameModelBuilder.cpp
        Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModelBuilder/FrameModelDirector.cpp
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
        Model/Visitors/BaseVisitor.cpp
        Model/Visitors/TransformObjectVisitor.cpp
        main.cpp
        View/view.cpp Model/Handlers/DrawHandler.cpp Model/Handlers/DrawHandler.h Model/Visitors/DrawObjectVisitor.cpp Model/Visitors/DrawObjectVisitor.h Model/Visitors/ProjectionVisitor.cpp Model/Visitors/ProjectionVisitor.h Model/Handlers/ProjectionHandler.cpp Model/Handlers/ProjectionHandler.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
