
/**
 * @class DS::Optical
 * Data Structure: Monte Carlo information
 *
 * @author Sean Hughes <sgshugh0@liverpool.ac.uk>
 *
 * Contains the information relating to printing out optical properties as meta data
 *
 */

#ifndef __RAT_DS_Optical__
#define __RAT_DS_Optical__

#include <TGraph.h>
#include <TObject.h>
#include <TTimeStamp.h>

#include <RAT/DB.hh>

namespace RAT {
namespace DS {

class Optical : public TObject {
 public:
  Optical() : TObject() {}
  virtual ~Optical() {}

  /**
   * function that prints the optical properties to the meta branch
   */
  std::vector<TGraph> GetOpticalProperty() {
    GetOPTICS();
    return opticalProperties;
  }

  void GetOPTICS() {
    DBLinkGroup mats = DB::Get()->GetLinkGroup("OPTICS");

    // Load everything in OPTICS
    for (DBLinkGroup::iterator iv = mats.begin(); iv != mats.end(); iv++) {
      std::string name = iv->first;
      std::cout << "Loading optics: " << name;
    }
  }

 private:
  std::string name;
  std::vector<TGraph> opticalProperties;
};
// ClassDef(Optical, 2);

}  // namespace DS
}  // namespace RAT

#endif
