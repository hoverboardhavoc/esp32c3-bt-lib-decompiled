/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_llcp_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_state_set(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (param_3 == 3) {
    if (param_2 == 2) goto _L78;
    uVar4 = 0x1a4;
    uVar3 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L78;
    uVar4 = 0x1a5;
    uVar3 = 0;
  }
  r_assert_param(param_2,uVar3,"llc.c",uVar4);
_L78:
  if (iVar1 != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar2 + 0x28) & 0x20) != 0) &&
       (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40a30024,
                 (uint)*(byte *)(iVar1 + 0x44) << 0x18 | param_3 << 0x10 | param_2 << 8 | param_1);
    }
    if (((*(byte *)(iVar1 + 0x44) & 3) != 3) &&
       (((int)(uint)*(byte *)(iVar1 + 0x44) >> 2 & 3U) != 3)) {
      if (param_2 != 1) {
        if (param_2 == 0) {
          if ((param_3 & 0xfffffffc) != 0) {
            r_assert_param(3,param_3,"llc.c",0x1b3);
          }
          *(byte *)(iVar1 + 0x44) = (byte)param_3 | *(byte *)(iVar1 + 0x44) & 0xfc;
          return;
        }
        if (param_2 != 2) {
          r_assert_param(param_1,param_2,"llc.c",0x1c4);
          return;
        }
        if ((param_3 & 0xfffffffc) != 0) {
          r_assert_param(3,param_3,"llc.c",0x1b8);
        }
        *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfc | (byte)param_3;
      }
      if ((param_3 << 2 & 0xfffffff3) != 0) {
        r_assert_param(0xc,param_3,"llc.c",0x1bc);
      }
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xf3 | (byte)(param_3 << 2);
      r_llc_llcp_tx_check(param_1);
      return;
    }
  }
  return;
}

