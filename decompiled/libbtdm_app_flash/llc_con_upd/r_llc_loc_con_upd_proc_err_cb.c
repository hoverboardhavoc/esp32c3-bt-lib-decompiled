/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_loc_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_con_upd_proc_err_cb(uint param_1,uint param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 3 - (*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) & 0xff;
  if (param_2 == 2) {
    uVar1 = (uint)param_3[1];
_L149:
    if (uVar1 == 0) goto _L148;
    if ((uVar1 - 0x19 & 0xff) < 2) goto _L150;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
_L162:
        uVar1 = 0;
        goto _L148;
      }
      uVar1 = 0;
      if (param_3[1] != 0xf) goto _L148;
      uVar1 = (uint)param_3[2];
      goto _L149;
    }
    if (param_2 == 0) {
      uVar1 = (uint)*param_3;
      uVar3 = 6;
      goto _L149;
    }
    if (param_3[1] != 0xf) goto _L162;
    uVar1 = 0x1a;
_L150:
    iVar2 = r_sdk_config_get_opts();
    if ((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0)
       ) {
      *(byte *)(iVar2 + 0x30) = *(byte *)(iVar2 + 0x30) & 0xfd;
    }
  }
  r_llc_loc_con_upd_proc_continue_hack(param_1,uVar3,uVar1);
_L148:
  r_ble_log_internal_x1(0x804f008b,uVar3 << 0x18 | param_2 << 8 | param_1 | uVar1 << 0x10);
  return;
}

