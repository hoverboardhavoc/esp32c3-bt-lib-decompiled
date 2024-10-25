/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_dl_chg_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_dl_chg_check(uint param_1,int param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  cVar1 = *(char *)(iVar4 + 0x1d);
  if (((*(char *)(iVar4 + 0x1c) == '\x03') == (param_2 == 3)) ||
     (uVar5 = r_co_ble_pkt_dur_in_us
                        (*(char *)(iVar4 + 0x14) + '\x04',
                         (uint)(1 < (byte)(*(char *)(iVar4 + 0x1c) - 1U)) << 1),
     *(ushort *)(iVar4 + 0x18) == uVar5)) {
    bVar3 = false;
    if ((cVar1 == '\x03') == (param_3 == 3)) {
      return;
    }
  }
  else {
    *(short *)(iVar4 + 0x18) = (short)uVar5;
    bVar3 = true;
    if ((cVar1 == '\x03') == (param_3 == 3)) goto _L17;
  }
  uVar5 = r_co_ble_pkt_dur_in_us
                    (*(char *)(iVar4 + 0x16) + '\x04',(uint)(1 < (byte)(cVar1 - 1U)) << 1);
  if (*(ushort *)(iVar4 + 0x1a) == uVar5) {
    if (!bVar3) {
      return;
    }
  }
  else {
    *(short *)(iVar4 + 0x1a) = (short)uVar5;
  }
_L17:
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x1104,param_1 & 0xffff,0x3e,0xc);
  *puVar6 = 7;
  uVar2 = *(undefined2 *)(iVar4 + 0x16);
  *(short *)(puVar6 + 2) = (short)param_1;
  *(undefined2 *)(puVar6 + 8) = uVar2;
  *(undefined2 *)(puVar6 + 10) = *(undefined2 *)(iVar4 + 0x1a);
  *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(iVar4 + 0x14);
  *(undefined2 *)(puVar6 + 6) = *(undefined2 *)(iVar4 + 0x18);
  r_hci_send_2_host();
  return;
}

