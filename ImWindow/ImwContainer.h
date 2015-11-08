
#ifndef __IMW_CONTAINER_H__
#define __IMW_CONTAINER_H__

#include "ImwConfig.h"
#include "ImwWindow.h"

namespace ImWindow
{
	class ImwPlatformWindow;
//STB_BEGIN
	class IMW_API ImwContainer
	{
		friend class ImwPlatformWindow;
	public:

		void							Dock(ImwWindow* pWindow, EDockOrientation eOrientation = E_DOCK_ORIENTATION_CENTER);
		bool							UnDock(ImwWindow* pWindow);
		void							DockToBest(ImwWindow* pWindow);

		bool							IsEmpty() const;
		bool							IsSplit() const;
		bool							HasWindowTabbed() const;
		ImwContainer*					HasWindow(const ImwWindow* pWindow);
		ImwPlatformWindow*				GetPlatformWindowParent() const;
		ImwContainer*					GetBestDocking(const ImVec2 oCursorPosInContainer, EDockOrientation& oOutOrientation, ImVec2& oOutAreaPos, ImVec2& oOutAreaSize, bool bLargeCheck);
		bool							HasUnclosableWindow() const;
	protected:
										ImwContainer(ImwContainer* pParent);
										ImwContainer(ImwPlatformWindow* pParent);
										~ImwContainer();

		void							CreateSplits();

		void							Paint();

		ImwContainer*					m_pParent;
		ImwPlatformWindow*				m_pParentWindow;
		ImwWindowList					m_lWindows;
		ImwContainer*					m_pSplits[2];

		float							m_fSplitRatio;
		bool							m_bVerticalSplit;
		int								m_iActiveWindow;

		bool							m_bIsDrag;

		ImVec2							m_oLastPosition;
		ImVec2							m_oLastSize;
	};
//STB_END
}

#endif // __IMW_CONTAINER_H__