/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_assert_param(param_1,1,"h4tl.c",0x4f5);
    r_assert_param(param_1,1,"h4tl.c",0x50d);
    return;
  }
  _r_ke_msg_alloc = param_2 + -1;
  _r_hci_send_2_host = param_4;
  _memset = (undefined2)param_3;
  if (r_hci_cmd_get_max_param_size == (code)0xff) {
    r_hci_cmd_get_max_param_size = (code)0x0;
                    /* WARNING: Could not recover jumptable at 0x0001073e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_h4tl_env + 4))(param_3 + 1,0x10000,&h4tl_env);
    return;
  }
  return;
}

