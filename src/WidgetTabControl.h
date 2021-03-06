/*
Copyright © 2011-2012 Clint Bellanger

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

#pragma once
#ifndef MENU_TAB_CONTROL_H
#define MENU_TAB_CONTROL_H

#include <vector>

#include "CommonIncludes.h"
#include "SharedResources.h"
#include "WidgetLabel.h"

class WidgetTabControl {

private:


	Sprite *activeTabSurface;
	Sprite *inactiveTabSurface;

	std::vector<WidgetLabel> active_labels;
	std::vector<WidgetLabel> inactive_labels;

	std::string *titles;  /** Titles of the tabs. */
	int activeTab;        /** Index of the currently active tab. */
	int tabsAmount;       /** Amount of tabs in the control. */

	Rect *tabs;       /** Rectangles for each tab title on the tab header. */
	Rect tabsArea;    /** Area the tab titles are displayed. */
	Rect contentArea; /** Area where the content of the {@link activeTab active tab} is displayed. */
	Point tabPadding;     /** Padding between tab titles. */
	Color color_normal;
	Color color_disabled;

	void loadGraphics();

	void renderTab(int number);

public:

	WidgetTabControl(int amount);
	WidgetTabControl(const WidgetTabControl &copy); // copy constructor not implemented
	~WidgetTabControl();

	void setTabTitle(int number, const std::string& title);
	void setMainArea(int x, int y, int width, int height);

	int getActiveTab();
	void setActiveTab(int tab) { activeTab = tab; }
	Rect getContentArea();
	int getTabHeight() { return activeTabSurface->getGraphicsHeight(); }

	void updateHeader();

	void logic();
	void logic(int x, int y);
	void render();
};

#endif
