/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_cleanup(uint param_1,int param_2)

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
  r_ble_log_internal_x1(0x400f0011,param_2 << 8 | param_1);
  return;
}

