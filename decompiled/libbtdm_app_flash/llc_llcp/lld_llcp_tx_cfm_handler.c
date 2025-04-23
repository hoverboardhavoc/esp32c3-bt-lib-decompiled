/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  param_1 = param_1 >> 8;
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (iVar2 == 0) {
    r_assert_param(0,"llc_llcp.c",0x3ec);
  }
  else {
    iVar1 = r_co_list_pop_front(iVar2 + 0x28);
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))(param_1,*(undefined1 *)(iVar1 + 9));
    }
    r_ke_free(iVar1);
    *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfffd;
  }
  r_llc_llcp_tx_check(param_1);
  return 0;
}

