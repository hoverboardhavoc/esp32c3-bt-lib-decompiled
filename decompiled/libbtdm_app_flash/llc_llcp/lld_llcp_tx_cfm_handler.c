/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> llc_llcp.o -> lld_llcp_tx_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_llcp_tx_cfm_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  uVar3 = param_1 >> 8 & 0xff;
  if (iVar1 == 0) {
    r_assert_param(0,"llc_llcp.c",0x3df);
  }
  else {
    iVar2 = r_co_list_pop_front(iVar1 + 0x28);
    if (*(code **)(iVar2 + 4) != (code *)0x0) {
      (**(code **)(iVar2 + 4))(uVar3,*(undefined1 *)(iVar2 + 9));
    }
    r_ke_free(iVar2);
    *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) & 0xfffd;
  }
  r_llc_llcp_tx_check(uVar3);
  return 0;
}

