/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_llcp_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_state_set(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if (param_3 == 3) {
    if (param_2 == 2) goto _L77;
    uVar3 = 0x1a7;
    uVar2 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L77;
    uVar3 = 0x1a8;
    uVar2 = 0;
  }
  r_assert_param(param_2,uVar2,"llc.c",uVar3);
_L77:
  if (iVar4 != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar1 + 0x28) & 0x20) != 0) &&
       (iVar1 = r_sdk_config_get_opts_ext(), *(byte *)(iVar1 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40a30024,
                 (uint)*(byte *)(iVar4 + 0x44) << 0x18 | param_3 << 0x10 | param_2 << 8 | param_1);
    }
    if (((*(byte *)(iVar4 + 0x44) & 3) != 3) &&
       (((int)(uint)*(byte *)(iVar4 + 0x44) >> 2 & 3U) != 3)) {
      if (param_2 != 1) {
        if (param_2 != 2) {
          if (param_2 == 0) {
            if ((param_3 & 0xfffffffc) != 0) {
              r_assert_param(3,param_3,"llc.c",0x1b6);
            }
            *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
            return;
          }
          r_assert_param(param_1,param_2,"llc.c",0x1c7);
          return;
        }
        if ((param_3 & 0xfffffffc) != 0) {
          r_assert_param(3,param_3,"llc.c",0x1bb);
        }
        *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
      }
      if ((param_3 << 2 & 0xfffffff3) != 0) {
        r_assert_param(0xc,param_3,"llc.c",0x1bf);
      }
      *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xf3 | (byte)(param_3 << 2);
      r_llc_llcp_tx_check(param_1);
      return;
    }
  }
  return;
}

