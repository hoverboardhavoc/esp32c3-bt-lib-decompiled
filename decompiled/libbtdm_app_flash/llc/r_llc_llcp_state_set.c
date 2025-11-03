/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_llcp_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_state_set(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (param_3 == 3) {
    if (param_2 == 2) goto _L79;
    uVar2 = 0x1ab;
    uVar1 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L79;
    uVar2 = 0x1ac;
    uVar1 = 0;
  }
  r_assert_param(param_2,uVar1,"llc.c",uVar2);
_L79:
  if (iVar3 != 0) {
    r_ble_log_internal_x1
              (0x404f0014,
               (uint)*(byte *)(iVar3 + 0x44) << 0x18 | param_2 << 8 | param_3 << 0x10 | param_1);
    if (((*(byte *)(iVar3 + 0x44) & 3) != 3) &&
       (((int)(uint)*(byte *)(iVar3 + 0x44) >> 2 & 3U) != 3)) {
      if (param_2 != 1) {
        if (param_2 != 2) {
          if (param_2 == 0) {
            if ((param_3 & 0xfffffffc) != 0) {
              r_assert_param(3,param_3,"llc.c",0x1bb);
            }
            *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfc | (byte)param_3;
            return;
          }
          r_assert_param(param_1,param_2,"llc.c",0x1cc);
          return;
        }
        if ((param_3 & 0xfffffffc) != 0) {
          r_assert_param(3,param_3,"llc.c",0x1c0);
        }
        *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfc | (byte)param_3;
      }
      if ((param_3 << 2 & 0xfffffff3) != 0) {
        r_assert_param(0xc,param_3,"llc.c",0x1c4);
      }
      *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xf3 | (byte)(param_3 << 2);
      r_llc_llcp_tx_check_hack(param_1);
      return;
    }
  }
  return;
}

