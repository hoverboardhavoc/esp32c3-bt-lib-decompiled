/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_connectable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_connectable_construct(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  ushort uVar9;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar2 = *(ushort *)(iVar4 + 0x74);
  uVar5 = ((uint)*(byte *)(iVar4 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar6 = r_lld_adv_ext_pkt_prepare(param_1,7,0,0,1);
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
  sVar3 = *(short *)(iVar4 + 0x82);
  iVar6 = r_lld_adv_ext_pkt_prepare
                    (param_1,uVar5,7,uVar2 & 3,1,*(ushort *)(iVar4 + 0x74) >> 2 & 1,0);
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
  if (sVar3 != 0) {
    r_assert_err(0,0x10000,0x627);
  }
  bVar1 = *(byte *)(iVar4 + 0x91);
  if ((bVar1 & 0xc0) != 0) {
    r_assert_err(0,0x10000,0x635);
  }
  iVar8 = param_1 * 0x5a;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar2 = *(ushort *)(iVar6 + iVar8 + 0x26);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar8 + 0x26) = uVar2 & 0x3ff | (ushort)bVar1 << 10;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar2 = *(ushort *)(iVar6 + iVar8 + 4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar8 + 4) = uVar2 & 0xffcf | 0x10;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar8 + 0x34 + iVar6) = (short)uVar5 * 0xe + 0x1400;
  cVar7 = *(char *)(iVar4 + 0x90);
  if (cVar7 == '\x03') {
    cVar7 = '\x02';
  }
  iVar6 = r_co_ble_pkt_dur_in_us(0x22,cVar7);
  bVar1 = *(byte *)(iVar4 + 0x87);
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6 + 0x96;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar9 = (ushort)bVar1 * 9 + 2 & 0xff;
  uVar2 = *(ushort *)(iVar6 + uVar5 * 0xe);
  iVar6 = r_emi_get_mem_addr_by_offset();
  *(ushort *)(uVar5 * 0xe + iVar6) = uVar9 * 0xe + 0x1400 | uVar2 & 0x8000;
  r_lld_adv_ext_pkt_prepare(param_1,uVar9,8,0,1,0,0);
  *(undefined1 *)(iVar4 + 0x92) = 3;
  return;
}

