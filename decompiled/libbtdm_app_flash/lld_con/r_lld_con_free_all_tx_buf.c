/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_free_all_tx_buf
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_free_all_tx_buf(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)&lld_con_env;
  for (iVar4 = 0; iVar2 = r_sdk_config_get_opts(), iVar4 < (int)(uint)*(byte *)(iVar2 + 0xd);
      iVar4 = iVar4 + 1) {
    iVar2 = *piVar1;
    if (iVar2 != 0) {
      while (iVar3 = r_co_list_pop_front(iVar2 + 0x28), iVar3 != 0) {
        r_ble_util_buf_acl_tx_free(*(undefined2 *)(iVar3 + 4));
      }
    }
    piVar1 = piVar1 + 1;
  }
  return;
}

