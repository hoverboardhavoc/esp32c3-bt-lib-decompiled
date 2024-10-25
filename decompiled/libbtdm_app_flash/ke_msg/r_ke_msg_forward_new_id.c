/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke_msg.o -> r_ke_msg_forward_new_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_msg_forward_new_id(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  *(undefined2 *)(param_1 + -8) = param_2;
  *(undefined2 *)(param_1 + -6) = param_3;
  *(undefined2 *)(param_1 + -4) = param_4;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back(&ke_env,param_1 + -0xc);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  r_ke_event_set(3);
  return;
}

