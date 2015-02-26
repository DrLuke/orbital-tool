#include <mainwin.hpp>

mainWin::mainWin(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> builder) : 
	Gtk::Window(cobject)
{
	builder->get_widget("mainList", mTreeView);
	
	mTreeStore = Glib::RefPtr<Gtk::TreeStore>::cast_dynamic(builder->get_object("mainTreeStore"));
	

	Gtk::TreeStore::iterator iter = mTreeStore->append();
	Gtk::TreeStore::Row row = *iter;

	row->set_value(mModelRecord.mID, 1337);
	row[mModelRecord.mName] = "Test Successful!";

	//mTreeView->get_column(0)->pack_start(mModelRecord.mID);
	//mTreeView->get_column(1)->pack_start(mModelRecord.mName);
	
}

mainWin::~mainWin()
{
	
}

void mainWin::onButtonClicked()
{
	std::cout << "Hello World!" << std::endl;
}

void mainWin::onTreeRowActivated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn* column)
{

}
