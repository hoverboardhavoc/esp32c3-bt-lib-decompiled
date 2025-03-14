/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_unreg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_unreg(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 << 8 | 1;
  uVar3 = r_ke_state_get(uVar4);
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param(param_1,param_2,"llc.c",0x1dd);
  }
  piVar2 = (int *)(iVar1 + param_2 * 4);
  if (*piVar2 == 0) {
    r_assert_param(param_1,param_2,"llc.c",0x1de);
  }
  r_llc_proc_timer_set(param_1,param_2,0);
  r_ke_msg_free(*piVar2 + -0xc);
  *piVar2 = 0;
  if (uVar3 != 0xff) {
    r_ke_state_set(uVar4,~(1 << (param_2 & 0x1f)) & uVar3 & 0xff);
    return;
  }
  return;
}

