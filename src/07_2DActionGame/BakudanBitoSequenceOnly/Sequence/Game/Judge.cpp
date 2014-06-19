#include "GameLib/GameLib.h"
#include "GameLib/Framework.h"
using namespace GameLib;

#include "Image.h"
#include "State.h"
#include "Sequence/Game/Judge.h"
#include "Sequence/Game/Parent.h"

namespace Sequence{
namespace Game{

Judge::Judge() : mImage( 0 ), mCursorPosistion( 0 ){
	mImage = new Image( "data/image/dummy.dds" );
}

Judge::~Judge(){
	SAFE_DELETE( mImage );
}

void Judge::update( Parent* parent ){
	Framework f = Framework::instance();;
	if ( f.isKeyTriggered( 'w' ) ){
		--mCursorPosistion;
		if ( mCursorPosistion < 0 ){ //�}�C�i�X�͍ő�l�Ƀ��[�v
 			mCursorPosistion = 1;
		}
	}else if ( f.isKeyTriggered( 'z' ) ){
		++mCursorPosistion;
		if ( mCursorPosistion > 1 ){ //1���z������0�Ƀ��[�v
			mCursorPosistion = 0;
		}
	}else if ( f.isKeyTriggered( ' ' ) ){
		if ( mCursorPosistion == 0 ){
			//�����ď���
			parent->moveTo( Parent::NEXT_READY );
		}else if ( mCursorPosistion == 1 ){
			//�^�C�g����
			parent->moveTo( Parent::NEXT_TITLE );
		}
	}
	//�`��
	//�܂��Q�[�����
	parent->state()->draw();
	//��ɏd�˂�
	mImage->draw();

	//�܂��ǂ������������̂��\��
	f.drawDebugString( 0, 0, "[���ʲ��ò]" );
	f.drawDebugString( 0, 1, "1P� ��!" );
	//�߂ʁ[
	f.drawDebugString( 1, 3, "��� �ۼ��" );
	f.drawDebugString( 1, 4, "��� ���� ���� �" );
	//�J�[�\��������
	f.drawDebugString( 0, mCursorPosistion + 3, ">" );
}



} //namespace Game
} //namespace Sequence