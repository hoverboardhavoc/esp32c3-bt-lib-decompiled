/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_unreg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_unreg(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = param_1 << 8 | 1;
  uVar1 = r_ke_state_get(uVar4);
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param(param_1,param_2,"llc.c",0x1e2);
  }
  piVar3 = (int *)(iVar2 + param_2 * 4);
  if (*piVar3 == 0) {
    r_assert_param(param_1,param_2,"llc.c",0x1e3);
  }
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40a30026,param_2 << 8 | param_1);
    }
  }
  r_llc_proc_timer_set(param_1,param_2,0);
  r_ke_msg_free(*piVar3 + -0xc);
  *piVar3 = 0;
  if (uVar1 != 0xff) {
    r_ke_state_set(uVar4,~(1 << (param_2 & 0x1f)) & uVar1 & 0xff);
    return;
  }
  return;
}

