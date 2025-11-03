/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_loc_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_phy_upd_proc_err_cb(uint param_1,uint param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 2) {
    uVar1 = (uint)param_3[1];
_L121:
    if (uVar1 == 0) goto _L120;
    if ((uVar1 - 0x19 & 0xff) < 2) goto _L122;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
_L134:
        uVar1 = 0;
        goto _L120;
      }
      uVar1 = 0;
      if (param_3[1] != 0x16) goto _L120;
      uVar1 = (uint)param_3[2];
      goto _L121;
    }
    if (param_2 == 0) {
      uVar1 = (uint)*param_3;
      goto _L121;
    }
    if (param_3[1] != 0x16) goto _L134;
    uVar1 = 0x19;
_L122:
    iVar2 = r_sdk_config_get_opts();
    if ((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0)
       ) {
      *(byte *)(iVar2 + 0x31) = *(byte *)(iVar2 + 0x31) & 0xfe;
    }
  }
  r_llc_loc_phy_upd_proc_continue_hack(param_1,0,uVar1);
_L120:
  r_ble_log_internal_x1(0x804f0042,param_2 << 8 | param_1 | uVar1 << 0x10);
  return;
}

