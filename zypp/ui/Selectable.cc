/*---------------------------------------------------------------------\
|                          ____ _   __ __ ___                          |
|                         |__  / \ / / . \ . \                         |
|                           / / \ V /|  _/  _/                         |
|                          / /__ | | | | | |                           |
|                         /_____||_| |_| |_|                           |
|                                                                      |
\---------------------------------------------------------------------*/
/** \file	zypp/ui/Selectable.cc
 *
*/
#include <iostream>
//#include "zypp/base/Logger.h"

#include "zypp/ui/Selectable.h"
#include "zypp/ui/SelectableImpl.h"

///////////////////////////////////////////////////////////////////
namespace zypp
{ /////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////
  namespace ui
  { /////////////////////////////////////////////////////////////////

    IMPL_PTR_TYPE(Selectable);

    ///////////////////////////////////////////////////////////////////
    //
    //	METHOD NAME : Selectable::Selectable
    //	METHOD TYPE : Ctor
    //
    Selectable::Selectable( Impl_Ptr pimpl_r )
    : _pimpl( pimpl_r )
    {}

    ///////////////////////////////////////////////////////////////////
    //
    //	METHOD NAME : Selectable::~Selectable
    //	METHOD TYPE : Dtor
    //
    Selectable::~Selectable()
    {}

    ///////////////////////////////////////////////////////////////////
    //
    // Forward to implementation.
    // Restrict PoolItems to ResObject::constPtr!
    //
    ///////////////////////////////////////////////////////////////////

    ResObject::Kind Selectable::kind() const
    { return _pimpl->kind(); }

    const std::string & Selectable::name() const
    { return _pimpl->name(); }

    Status Selectable::status() const
    { return _pimpl->status(); }

    bool Selectable::setStatus( const Status state_r )
    { return _pimpl->setStatus( state_r ); }

    PoolItem Selectable::installedObj() const
    { return _pimpl->installedObj(); }

    PoolItem Selectable::candidateObj() const
    { return _pimpl->candidateObj(); }

    PoolItem Selectable::setCandidate( ResObject::constPtr byUser_r )
    { return _pimpl->setCandidate( byUser_r ); }

    PoolItem Selectable::theObj() const
    { return _pimpl->theObj(); }

    ////////////////////////////////////////////////////////////////////////

    bool Selectable::availableEmpty() const
    { return _pimpl->availableEmpty(); }

    Selectable::available_size_type Selectable::availableSize() const
    { return _pimpl->availableSize(); }

    Selectable::available_iterator Selectable::availableBegin() const
    { return _pimpl->availableBegin(); }

    Selectable::available_iterator Selectable::availableEnd() const
    { return _pimpl->availableEnd(); }

    ////////////////////////////////////////////////////////////////////////

    bool Selectable::installedEmpty() const
    { return _pimpl->installedEmpty(); }

    Selectable::installed_size_type Selectable::installedSize() const
    { return _pimpl->installedSize(); }

    Selectable::installed_iterator Selectable::installedBegin() const
    { return _pimpl->installedBegin(); }

    Selectable::installed_iterator Selectable::installedEnd() const
    { return _pimpl->installedEnd(); }


    ////////////////////////////////////////////////////////////////////////

    bool Selectable::isUnmaintained() const
    { return _pimpl->isUnmaintained(); }



    ResStatus::TransactByValue Selectable::modifiedBy() const
    { return _pimpl->modifiedBy(); }

    bool Selectable::hasLicenceConfirmed() const
    { return _pimpl->hasLicenceConfirmed(); }

    void Selectable::setLicenceConfirmed( bool val_r )
    { _pimpl->setLicenceConfirmed( val_r ); }


    Selectable::Fate Selectable::fate() const
    {
      switch ( status() ) {
      case S_Update:
      case S_Install:
      case S_AutoUpdate:
      case S_AutoInstall:
        return TO_INSTALL;
        break;

      case S_Del:
      case S_AutoDel:
        return TO_DELETE;
        break;

      case S_Protected:
      case S_Taboo:
      case S_KeepInstalled:
      case S_NoInst:
        break;
      }
      return UNMODIFIED;
    };


    /******************************************************************
    **
    **	FUNCTION NAME : operator<<
    **	FUNCTION TYPE : std::ostream &
    */
    std::ostream & operator<<( std::ostream & str, const Selectable & obj )
    {
      return str << *obj._pimpl;
    }

    /////////////////////////////////////////////////////////////////
  } // namespace ui
  ///////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////
} // namespace zypp
///////////////////////////////////////////////////////////////////
