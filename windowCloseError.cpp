#include "ace.h"
#ifdef _DEBUG
#pragma comment(lib, "Debug/ace_engine.lib")
#else
#pragma comment(lib, "Release/ace_engine.lib")
#endif
/*
���e: �E�B���h�E�I�����ɃG���[����������

��������錴��:
�O���[�o���ϐ��Ƀe�N�X�`�������Ȃǂ��āAEngine::Terminate()���Ă΂ꂽ���Ƃ�
���\�[�X������N����ƃG���[�ɂȂ�B

*/


using namespace ace;

namespace ImgManager {
	void setTexture2D(std::shared_ptr<Texture2D>& tex, char const* file) {
		tex = Engine::GetGraphics()->CreateTexture2D(ToAString(file).c_str());
	}
	std::shared_ptr<Texture2D> img; // �O���[�o���ϐ��Ƀ��\�[�X��u��
	void init() {
		setTexture2D(img, "img.png");
	}
}

class EngineProvider {
public:
	EngineProvider() {
		auto opt = ace::EngineOption();
		opt.GraphicsType = ace::eGraphicsType::GRAPHICS_TYPE_GL;
		opt.IsFullScreen = false;
		opt.IsMultithreadingMode = true;
		if(!ace::Engine::Initialize(ace::ToAString("Test").c_str(), 800, 600, opt)){ assert(!"Err in init"); };
		Engine::SetTargetFPS(60);
	}

	virtual ~EngineProvider() {
		ace::Engine::Terminate();
	}

};

int main() {
	EngineProvider engineProvider;
	ImgManager::init();
	while(Engine::DoEvents()) {

	}

}