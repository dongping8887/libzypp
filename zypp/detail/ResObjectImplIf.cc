/*---------------------------------------------------------------------\
|                          ____ _   __ __ ___                          |
|                         |__  / \ / / . \ . \                         |
|                           / / \ V /|  _/  _/                         |
|                          / /__ | | | | | |                           |
|                         /_____||_| |_| |_|                           |
|                                                                      |
\---------------------------------------------------------------------*/
/** \file	zypp/detail/ResObjectImplIf.cc
 *
*/
#include "zypp/detail/ResObjectImplIf.h"
#include "zypp/source/SourceImpl.h"
#include "zypp/SourceFactory.h"

///////////////////////////////////////////////////////////////////
namespace zypp
{ /////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////
  namespace detail
  { /////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////
    // Default implementation of ResObjectImplIf attributes,
    // as far as resonable.
    /////////////////////////////////////////////////////////////////

      Label ResObjectImplIf::summary() const
      { return Label(); }

      Text ResObjectImplIf::description() const
      { return Text(); }

      Text ResObjectImplIf::insnotify() const
      { return Text(); }

      Text ResObjectImplIf::delnotify() const
      { return Text(); }

      ByteCount ResObjectImplIf::size() const
      { return 0; }

      bool ResObjectImplIf::providesSources() const
      { return false; }

      Source ResObjectImplIf::source() const
      { return SourceFactory().createFrom(source::SourceImpl::nullimpl()); }

      Label ResObjectImplIf::instSrcLabel() const
      { return Label(); }

      Vendor ResObjectImplIf::instSrcVendor() const
      { return Vendor(); }

    /////////////////////////////////////////////////////////////////
  } // namespace detail
  ///////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////
} // namespace zypp
///////////////////////////////////////////////////////////////////
