/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_dl_chg_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_dl_chg_check(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  uVar4 = (uint)*(byte *)(iVar3 + 0x1d);
  if (((*(byte *)(iVar3 + 0x1c) == 3) == (param_2 == 3)) ||
     (uVar5 = r_co_ble_pkt_dur_in_us
                        (*(short *)(iVar3 + 0x14) + 4U & 0xff,
                         (uint)(1 < *(byte *)(iVar3 + 0x1c) - 1) << 1),
     *(ushort *)(iVar3 + 0x18) == uVar5)) {
    bVar2 = false;
    if ((uVar4 == 3) == (param_3 == 3)) {
      return;
    }
  }
  else {
    *(short *)(iVar3 + 0x18) = (short)uVar5;
    bVar2 = true;
    if ((uVar4 == 3) == (param_3 == 3)) goto _L16;
  }
  uVar4 = r_co_ble_pkt_dur_in_us(*(short *)(iVar3 + 0x16) + 4U & 0xff,(uint)(1 < uVar4 - 1) << 1);
  if (*(ushort *)(iVar3 + 0x1a) == uVar4) {
    if (!bVar2) {
      return;
    }
  }
  else {
    *(short *)(iVar3 + 0x1a) = (short)uVar4;
  }
_L16:
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x1104,param_1,0x3e,0xc);
  *puVar6 = 7;
  *(undefined2 *)(puVar6 + 8) = *(undefined2 *)(iVar3 + 0x16);
  *(undefined2 *)(puVar6 + 10) = *(undefined2 *)(iVar3 + 0x1a);
  uVar1 = *(undefined2 *)(iVar3 + 0x14);
  *(short *)(puVar6 + 2) = (short)param_1;
  *(undefined2 *)(puVar6 + 4) = uVar1;
  *(undefined2 *)(puVar6 + 6) = *(undefined2 *)(iVar3 + 0x18);
  r_hci_send_2_host();
  return;
}

