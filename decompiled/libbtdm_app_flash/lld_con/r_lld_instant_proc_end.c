/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_instant_proc_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_instant_proc_end(uint param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar3 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40a30010,(uint)*(byte *)(iVar2 + 0x46) << 8 | param_1);
    }
  }
  cVar1 = *(char *)(iVar2 + 0x46);
  if (cVar1 == '\x02') {
    uVar4 = 0x210;
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        r_ke_msg_send_basic(0x20f,param_1 << 8 | 1,0xff);
        r_lld_con_evt_time_update_eco(param_1);
        r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100));
      }
      else {
        r_assert_warn(0,0,"lld_con.c",0x81a);
      }
      goto _L286;
    }
    *(undefined1 *)(iVar2 + 0x93) = *(undefined1 *)(iVar2 + 0x35);
    *(undefined1 *)(iVar2 + 0x94) = *(undefined1 *)(iVar2 + 0x34);
    r_lld_con_evt_time_update_eco(param_1);
    r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100));
    uVar4 = 0x211;
  }
  r_ke_msg_send_basic(uVar4,param_1 << 8 | 1,0xff);
_L286:
  *(undefined1 *)(iVar2 + 0x46) = 0;
  return;
}

