#include "transformvisitor.hpp"
#include "arch/entities/camera.hpp"
#include "arch/entities/model.hpp"
#include "arch/entities/objectgroup.hpp"


TransformVisitor::TransformVisitor(size_t id, const Matrix& matrix)
    : id(id), matrix(matrix)
{
}

void TransformVisitor::visit(Camera &camera)
{
    if (camera.getId() == id)
        applyTransform(camera);
}

void TransformVisitor::visit(Model &model)
{
    if (model.getId() == id)
        applyTransform(model);
}

void TransformVisitor::visit(ObjectGroup &group)
{
    for (auto obj : group)
        obj->accept(*this);
}

void TransformVisitor::applyTransform(BaseObject& obj)
{
    auto mat = obj.getMatrix();
    mat = matrix * mat;
    obj.setMatrix(mat);
}
