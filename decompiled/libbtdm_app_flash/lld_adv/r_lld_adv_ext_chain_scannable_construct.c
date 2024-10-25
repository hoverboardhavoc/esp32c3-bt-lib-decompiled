/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_scannable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_scannable_construct(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar4 = *(ushort *)(iVar3 + 0x74) & 3;
  uVar8 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,7,uVar4,0,0,1,1);
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,uVar8,7,uVar4,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
  uVar9 = (uint)*(byte *)(iVar3 + 0x91) << 10;
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  if ((uVar9 & 0x30000) != 0) {
    r_assert_err(0,"lld_adv.c",0x635);
  }
  iVar5 = param_1 * 0x5a;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar4 = *(ushort *)(iVar6 + iVar5 + 0x26);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar5 + 0x26) = uVar4 & 0x3ff | (ushort)uVar9;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar4 = *(ushort *)(iVar6 + iVar5 + 4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar5 + 4) = uVar4 & 0xffcf | 0x10;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar5 + 0x34 + iVar6) = (short)uVar8 * 0xe + 0x1400;
  cVar2 = *(char *)(iVar3 + 0x90);
  if (cVar2 == '\x03') {
    cVar2 = '\x02';
  }
  iVar5 = r_co_ble_pkt_dur_in_us(0xc,cVar2);
  bVar7 = *(byte *)(iVar3 + 0x87);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5 + 0x96;
  sVar1 = *(short *)(iVar3 + 0x84);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar9 = (uint)bVar7 * 9 + 2 & 0xff;
  uVar4 = *(ushort *)(iVar5 + uVar8 * 0xe);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(uVar8 * 0xe + iVar5) = (short)uVar9 * 0xe + 0x1400U | uVar4 & 0x8000;
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,uVar9,7,0,1,0,0,0);
  cVar2 = '\x02';
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  while (cVar2 = cVar2 + '\x01', sVar1 != 0) {
    bVar7 = *(char *)(iVar3 + 0x87) * '\t' + cVar2;
    iVar5 = uVar9 * 0xe;
    uVar9 = (uint)bVar7;
    iVar6 = r_lld_adv_ext_pkt_prepare(param_1,uVar9,7,0,0,0,0,0);
    *(int *)(iVar3 + 0x6c) = iVar6 + *(int *)(iVar3 + 0x6c);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar6) = (ushort)bVar7 * 0xe + 0x1400 | uVar4 & 0x8000;
  }
  *(char *)(iVar3 + 0x92) = cVar2;
  return;
}

