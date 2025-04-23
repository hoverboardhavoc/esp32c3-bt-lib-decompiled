/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_write(int param_1,int param_2,int param_3,undefined4 param_4)

{
  r_rwip_prevent_sleep_set(2);
  *(char *)(param_2 + -1) = (char)param_1;
  if (4 < (param_1 - 1U & 0xff)) {
    r_assert_param(param_1,1,0x10000,0x4f5);
    r_assert_param(param_1,1,0x10000,0x50d);
    return;
  }
  _r_hci_send_2_host = param_2 + -1;
  _r_hci_cmd_get_max_param_size = (undefined2)param_3;
  _memset = param_4;
  if (r_ke_malloc == (code)0xff) {
    r_ke_malloc = (code)0x0;
                    /* WARNING: Could not recover jumptable at 0x0001075e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_h4tl_env + 4))(param_3 + 1,r_h4tl_tx_done,&h4tl_env,*(code **)(_h4tl_env + 4));
    return;
  }
  return;
}

