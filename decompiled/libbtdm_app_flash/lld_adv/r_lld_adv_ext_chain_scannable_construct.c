/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_scannable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_scannable_construct(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  char cVar9;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar3 + 0x74);
  uVar8 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,7,0,0,1);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
  iVar5 = r_lld_adv_ext_pkt_prepare
                    (param_1,uVar8,7,uVar1 & 3,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,0);
  bVar7 = *(byte *)(iVar3 + 0x91);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
  if ((bVar7 & 0xc0) != 0) {
    r_assert_err(0,0x10000,0x635);
  }
  iVar5 = param_1 * 0x5a;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar6 + iVar5 + 0x26);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar5 + 0x26) = uVar1 & 0x3ff | (ushort)bVar7 << 10;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar6 + iVar5 + 4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar5 + 4) = uVar1 & 0xffcf | 0x10;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar5 + 0x34 + iVar6) = (short)uVar8 * 0xe + 0x1400;
  cVar9 = *(char *)(iVar3 + 0x90);
  if (cVar9 == '\x03') {
    cVar9 = '\x02';
  }
  iVar5 = r_co_ble_pkt_dur_in_us(0xc,cVar9);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5 + 0x96;
  sVar2 = *(short *)(iVar3 + 0x84);
  uVar4 = (uint)*(byte *)(iVar3 + 0x87) * 9 + 2 & 0xff;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar1 = *(ushort *)(iVar5 + uVar8 * 0xe);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(uVar8 * 0xe + iVar5) = (short)uVar4 * 0xe + 0x1400U | uVar1 & 0x8000;
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,uVar4,7,0,1,0,0,0);
  cVar9 = '\x02';
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
  while (cVar9 = cVar9 + '\x01', sVar2 != 0) {
    bVar7 = *(char *)(iVar3 + 0x87) * '\t' + cVar9;
    iVar5 = r_lld_adv_ext_pkt_prepare(param_1,(uint)bVar7,7,0,0,0,0,0);
    *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar5 + uVar4 * 0xe);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(uVar4 * 0xe + iVar5) = (ushort)bVar7 * 0xe + 0x1400 | uVar1 & 0x8000;
    uVar4 = (uint)bVar7;
  }
  *(char *)(iVar3 + 0x92) = cVar9;
  return;
}

