/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_ral_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_lld_ral_search(undefined4 param_1,ushort param_2)

{
  uint uVar1;
  int iVar2;
  void *__src;
  undefined1 auStack_38 [16];
  
  uVar1 = 0;
  do {
    iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
    if (*(short *)(iVar2 + uVar1 * 0x34) < 0) {
      __src = (void *)r_emi_get_mem_addr_by_offset(uVar1 * 0x34 + 0xc78 & 0xffff);
      memcpy(auStack_38,__src,6);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      if (((param_2 & 1) == (*(ushort *)(iVar2 + uVar1 * 0x34) & 1)) &&
         (iVar2 = r_co_bdaddr_compare(auStack_38,param_1), iVar2 != 0)) {
        return uVar1 & 0xff;
      }
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 10) {
      return 10;
    }
  } while( true );
}

