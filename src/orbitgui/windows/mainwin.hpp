#ifndef __ORBITALGUI_MAINWIN_HPP
#define __ORBITALGUI_MAINWIN_HPP

#include <gtkmm.h>
#include <iostream>

class mainWin : public Gtk::Window
{
public:
	mainWin(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> builder);
	virtual ~mainWin();

protected:
	// Builder for reading glade data
	Glib::RefPtr<Gtk::Builder> mBuilder;

	// Signal Handlers
	void onButtonClicked();
	void onTreeRowActivated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn* column);
	
	class orbModelColumns : public Gtk::TreeModelColumnRecord
	{
	public:
		Gtk::TreeModelColumn<int> mID;
		Gtk::TreeModelColumn<Glib::ustring> mName;
		
		orbModelColumns()
		{
			add(mID);
			add(mName);
		}
	};
	
	// Column Record
	orbModelColumns mModelRecord;

	// Model Object
	Glib::RefPtr<Gtk::TreeStore> mTreeStore;

	// Member Widgets
	Gtk::TreeView* mTreeView;
	//Gtk::TreeModelColumn<int>* mColumnId;
	//Gtk::TreeModelColumn<Glib::ustring>* mColumnName;
	
	Glib::RefPtr<Gtk::TreeStore> mRefTreeModel;
};

#endif /* __ORBITALGUI_MAINWIN_HPP */
