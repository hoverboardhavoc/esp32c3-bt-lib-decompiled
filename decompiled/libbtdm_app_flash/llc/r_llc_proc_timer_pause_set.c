/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_timer_pause_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_timer_pause_set(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x282);
  }
  if ((iVar6 != 0) && (iVar6 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4), iVar6 != 0)
     ) {
    bVar1 = *(byte *)(iVar6 + 6);
    if (bVar1 == 2) {
      if (param_3 == 0) {
        bVar3 = true;
        *(undefined1 *)(iVar6 + 6) = 1;
_L199:
        iVar6 = (param_2 != 0) + 0x100;
        if (!bVar3) {
          r_ke_timer_clear(iVar6);
          return;
        }
        iVar2 = r_sdk_config_get_opts();
        iVar5 = *(int *)(&llc_env + param_1 * 4);
        if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar5 != 0)) &&
           ((*(byte *)(iVar5 + 0x44) & 3) != 3)) {
          uVar4 = 4000;
        }
        else {
          uVar4 = *(undefined2 *)(iVar5 + 0x12);
        }
        r_ke_timer_set(iVar6,param_1 << 8 | 1,uVar4);
        return;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        if (param_3 != 0) {
          *(undefined1 *)(iVar6 + 6) = 3;
        }
      }
      else if (param_3 != 0) {
        *(undefined1 *)(iVar6 + 6) = 2;
        bVar3 = false;
        goto _L199;
      }
    }
    else {
      if (bVar1 != 3) {
        r_assert_param(*(undefined1 *)(iVar6 + 4),"llc.c",0x2b6);
        return;
      }
      if (param_3 == 0) {
        *(undefined1 *)(iVar6 + 6) = 0;
      }
    }
  }
  return;
}

