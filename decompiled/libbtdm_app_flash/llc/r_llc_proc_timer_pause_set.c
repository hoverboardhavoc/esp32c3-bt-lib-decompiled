/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_timer_pause_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_timer_pause_set(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x28b);
  }
  if (iVar3 == 0) {
    return;
  }
  iVar3 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4);
  if (iVar3 == 0) {
    return;
  }
  bVar1 = *(byte *)(iVar3 + 6);
  if (bVar1 == 2) {
    if (param_3 != 0) goto _L183;
    *(undefined1 *)(iVar3 + 6) = 1;
    uVar2 = 1;
  }
  else {
    if (2 < bVar1) {
      if (bVar1 == 3) {
        if (param_3 == 0) {
          *(undefined1 *)(iVar3 + 6) = 0;
        }
      }
      else {
        r_assert_param(*(undefined1 *)(iVar3 + 4),"llc.c",0x2bf);
      }
      goto _L183;
    }
    if (bVar1 == 0) {
      if (param_3 != 0) {
        *(undefined1 *)(iVar3 + 6) = 3;
      }
      goto _L183;
    }
    if (param_3 == 0) goto _L183;
    *(undefined1 *)(iVar3 + 6) = 2;
    uVar2 = 0;
  }
  r_llc_llcp_trans_timer_set(param_1,param_2,uVar2);
_L183:
  r_ble_log_internal_x1
            (0x400f0018,
             (uint)*(byte *)(iVar3 + 6) << 0x18 | param_2 << 8 | param_3 << 0x10 | param_1);
  return;
}

