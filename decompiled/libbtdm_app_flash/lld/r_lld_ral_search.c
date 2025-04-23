/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  int iVar3;
  void *__src;
  undefined1 auStack_28 [8];
  
  uVar1 = 0;
  do {
    iVar2 = uVar1 * 0x34;
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    if (*(short *)(iVar3 + iVar2) < 0) {
      __src = (void *)r_emi_get_mem_addr_by_offset(iVar2 + 0xc78U & 0xffff);
      memcpy(auStack_28,__src,6);
      iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((((param_2 ^ *(ushort *)(iVar2 + iVar3)) & 1) == 0) &&
         (iVar2 = r_co_bdaddr_compare(auStack_28,param_1), iVar2 != 0)) {
        return uVar1 & 0xff;
      }
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 10) {
      return 10;
    }
  } while( true );
}

