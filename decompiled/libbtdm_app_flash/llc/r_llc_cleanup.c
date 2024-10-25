/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_cleanup(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(&llc_env + param_1 * 4);
  piVar1 = (int *)piVar2[10];
  while (piVar1 != (int *)0x0) {
    piVar1 = (int *)*piVar1;
    r_ke_free();
  }
  if (piVar2[1] != 0) {
    r_ke_free(piVar2[1] + -0xc);
  }
  if (*piVar2 != 0) {
    r_ke_free(*piVar2 + -0xc);
  }
  r_llc_llcp_trans_timer_set(param_1,0,0);
  r_llc_llcp_trans_timer_set(param_1,1,0);
  r_ke_state_set(param_1 << 8 | 1,0xff);
  r_ke_free(piVar2);
  *(undefined4 *)(&llc_env + param_1 * 4) = 0;
  return;
}

