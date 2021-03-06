#include <wx/xml/xml.h>

#include "BaseObject.h"
#include "ModelScreenLocation.h"

BaseObject::BaseObject()
: ModelXml(nullptr), changeCount(0)
{
    //ctor
}

BaseObject::~BaseObject()
{
    //dtor
}

wxXmlNode* BaseObject::GetModelXml() const {
    return this->ModelXml;
}

void BaseObject::SetLayoutGroup(const std::string &grp) {
    layout_group = grp;
    ModelXml->DeleteAttribute("LayoutGroup");
    ModelXml->AddAttribute("LayoutGroup", grp);
    IncrementChangeCount();
}

void BaseObject::MoveHandle3D(ModelPreview* preview, int handle, bool ShiftKeyPressed, bool CtrlKeyPressed, int mouseX, int mouseY, bool latch, bool scale_z)
{
    if (GetBaseObjectScreenLocation().IsLocked()) return;

    int i = GetBaseObjectScreenLocation().MoveHandle3D(preview, handle, ShiftKeyPressed, CtrlKeyPressed, mouseX, mouseY, latch, scale_z);
    GetBaseObjectScreenLocation().Write(ModelXml);
    if (i) {
        SetFromXml(ModelXml);
    }
    IncrementChangeCount();
}

void BaseObject::SelectHandle(int handle) {
    GetBaseObjectScreenLocation().SelectHandle(handle);
}

void BaseObject::Lock(bool lock)
{
    GetBaseObjectScreenLocation().Lock(lock);
    GetModelXml()->DeleteAttribute("Locked");
    if (lock)
    {
        GetModelXml()->AddAttribute("Locked", "1");
    }
    IncrementChangeCount();
}

void BaseObject::SetTop(float y) {

   if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetTop(y);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetBottom(float y) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetBottom(y);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetLeft(float x) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetLeft(x);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetRight(float x) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetRight(x);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetFront(float z) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetFront(z);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetBack(float z) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetBack(z);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetWidth(float w) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetMWidth(w);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetHeight(float h) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetMHeight(h);
    GetBaseObjectScreenLocation().Write(ModelXml);
    SetFromXml(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetHcenterPos(float pos) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetHcenterPos(pos);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

void BaseObject::SetVcenterPos(float pos) {

    if (GetBaseObjectScreenLocation().IsLocked()) return;

    GetBaseObjectScreenLocation().SetVcenterPos(pos);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
}

bool BaseObject::Scale(float f) {
    if (GetBaseObjectScreenLocation().IsLocked()) return false;
    
    bool b = GetBaseObjectScreenLocation().Scale(f);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
    return b;
}
bool BaseObject::Rotate(int axis, float factor) {
    if (GetBaseObjectScreenLocation().IsLocked()) return false;
    
    bool b = GetBaseObjectScreenLocation().Rotate(axis, factor);
    GetBaseObjectScreenLocation().Write(ModelXml);
    IncrementChangeCount();
    return b;
}

float BaseObject::GetTop() {
    return GetBaseObjectScreenLocation().GetTop();
}

float BaseObject::GetBottom() {
    return GetBaseObjectScreenLocation().GetBottom();
}

float BaseObject::GetLeft() {
    return GetBaseObjectScreenLocation().GetLeft();
}

float BaseObject::GetRight() {
    return GetBaseObjectScreenLocation().GetRight();
}

float BaseObject::GetFront() {
    return GetBaseObjectScreenLocation().GetFront();
}

float BaseObject::GetBack() {
    return GetBaseObjectScreenLocation().GetBack();
}

float BaseObject::GetWidth() {
    return GetBaseObjectScreenLocation().GetMWidth();
}

float BaseObject::GetHeight() {
    return GetBaseObjectScreenLocation().GetMHeight();
}

float BaseObject::GetHcenterPos() {
    return GetBaseObjectScreenLocation().GetHcenterPos();
}

float BaseObject::GetVcenterPos() {
    return GetBaseObjectScreenLocation().GetVcenterPos();
}
