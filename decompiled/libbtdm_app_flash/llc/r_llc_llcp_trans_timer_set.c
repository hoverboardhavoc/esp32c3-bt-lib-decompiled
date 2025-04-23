/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_llcp_trans_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_trans_timer_set(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  
  iVar1 = (param_2 != 0) + 0x100;
  if (param_3 != 0) {
    iVar2 = r_sdk_config_get_opts();
    iVar4 = *(int *)(&llc_env + param_1 * 4);
    if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar4 != 0)) && ((*(byte *)(iVar4 + 0x44) & 3) != 3)
       ) {
      uVar3 = 4000;
    }
    else {
      uVar3 = *(undefined2 *)(iVar4 + 0x12);
    }
    r_ke_timer_set(iVar1,param_1 << 8 | 1,uVar3);
    return;
  }
  r_ke_timer_clear(iVar1);
  return;
}

