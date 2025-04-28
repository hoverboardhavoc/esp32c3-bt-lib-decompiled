/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 auStack_38 [12];
  
  uVar1 = 0;
  do {
    iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
    if (*(short *)(iVar2 + uVar1 * 0x34) < 0) {
      __src = (void *)r_emi_get_mem_addr_by_offset(uVar1 * 0x34 + 0xc78 & 0xffff);
      memcpy(auStack_38,__src,6);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((((param_2 ^ *(ushort *)(uVar1 * 0x34 + iVar2)) & 1) == 0) &&
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

