/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_instant_proc_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_instant_proc_end(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  cVar1 = *(char *)(iVar2 + 0x46);
  if (cVar1 == '\x02') {
    uVar3 = 0x210;
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        r_ke_msg_send_basic(0x20f,param_1 << 8 | 1,0xff);
        r_lld_con_evt_time_update_eco(param_1);
        r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100));
      }
      else {
        r_assert_warn(0,0,"lld_con.c",0x803);
      }
      goto _L263;
    }
    *(undefined1 *)(iVar2 + 0x93) = *(undefined1 *)(iVar2 + 0x35);
    *(undefined1 *)(iVar2 + 0x94) = *(undefined1 *)(iVar2 + 0x34);
    r_lld_con_evt_time_update_eco();
    r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100));
    uVar3 = 0x211;
  }
  r_ke_msg_send_basic(uVar3,param_1 << 8 | 1,0xff);
_L263:
  *(undefined1 *)(iVar2 + 0x46) = 0;
  return;
}

