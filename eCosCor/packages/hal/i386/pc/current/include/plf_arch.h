#ifndef CYGONCE_HAL_PLF_ARCH_H
#define CYGONCE_HAL_PLF_ARCH_H

//=============================================================================
//
//      plf_arch.h
//
//      PC platform specific abstractions
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//=============================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):   proven
// Contributors:proven, pjo, nickg
// Date:        1998-10-05
// Purpose:     Define architecture abstractions
// Usage:       #include <cyg/hal/plf_arch.h>
//
//####DESCRIPTIONEND####
//
//=============================================================================

#include <pkgconf/hal.h>
#include <cyg/infra/cyg_type.h>

#ifdef CYGDBG_HAL_DEBUG_GDB_BREAK_SUPPORT
#define CYG_HAL_GDB_ENTER_CRITICAL_IO_REGION( _old_ )                        \
do {                                                                         \
    HAL_DISABLE_INTERRUPTS(_old_);                                           \
    cyg_hal_gdb_place_break((target_register_t)__builtin_return_address(0)); \
} while ( 0 )

#define CYG_HAL_GDB_LEAVE_CRITICAL_IO_REGION( _old_ )                         \
do {                                                                          \
    cyg_hal_gdb_remove_break((target_register_t)__builtin_return_address(0)); \
    HAL_RESTORE_INTERRUPTS(_old_);                                            \
} while ( 0 )
#endif

//--------------------------------------------------------------------------
#endif // CYGONCE_HAL_PLF_ARCH_H
// End of plf_arch.h
