#include "$projectname$.hpp"

$safeprojectname$::$safeprojectname$(std::wistream& s) {
    s >> color;

    // read data here
}

void $safeprojectname$::load(Engine& e) {
    auto& target = *e.display.renderTarget;
    HRESULT hr;
    hr = target.CreateSolidColorBrush(color, (ID2D1SolidColorBrush**)&brush);
    CHECK;
    
    // initialization code here
}

void $safeprojectname$::render(Engine& e) {
    auto& target = *e.display.renderTarget;

    // render code here
}

void $safeprojectname$::Release() {
    release(brush);

    // release code here
}

IWidget* factory(std::wistream& s) {
    return new $safeprojectname$(s);
}
