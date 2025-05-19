/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_priv_mode_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_res_list_priv_mode_update_hack(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = r_lld_ral_search();
  if (uVar2 < 10) {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar3 + uVar2 * 0x34);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(uVar2 * 0x34 + iVar3) = (ushort)(param_1 == 1) << 0xb | uVar1 & 0xf7ff;
    uVar4 = 0;
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

