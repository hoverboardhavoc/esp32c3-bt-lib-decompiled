/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  _r_ke_msg_alloc = param_2 + -1;
  _memset = (undefined2)param_3;
  _r_hci_send_2_host = param_4;
  if (r_hci_cmd_get_max_param_size == (code)0xff) {
    r_hci_cmd_get_max_param_size = (code)0x0;
                    /* WARNING: Could not recover jumptable at 0x0001073c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_h4tl_env + 4))(param_3 + 1,r_h4tl_tx_done,&h4tl_env,*(code **)(_h4tl_env + 4));
    return;
  }
  return;
}

