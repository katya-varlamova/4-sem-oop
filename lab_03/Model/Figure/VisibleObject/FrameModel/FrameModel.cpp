#include "FrameModel.h"
#include "FrameModelBuilder/FrameModelDirector.h"
#include "FrameModelBuilder/FrameModelBuilder.h"
FrameModel::FrameModel(std::shared_ptr<Primitive> primitives, std::vector<double>worldOffset)
{
    this->primitives = primitives;
    this->worldOffset = worldOffset;
}
std::shared_ptr<BaseObject> FrameModel::clone()
{
    std::shared_ptr<BaseFrameModelBuilder> builder(new FrameModelBuilder(primitives->getPoints(), primitives->getEdges(), worldOffset));
    std::shared_ptr<BaseFrameModelDirector> director(new FrameModelDirector());
    return director->createFrameModel(builder);
}
bool FrameModel::isComposite()
{
    return false;
}
void FrameModel::transform(Matrix<double> &matrix)
{
    primitives->transform(matrix);
}
void FrameModel::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    visitor->visit(*this);
}