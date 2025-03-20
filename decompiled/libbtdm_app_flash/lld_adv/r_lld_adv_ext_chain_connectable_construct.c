/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_connectable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_connectable_construct(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar7 = *(ushort *)(iVar3 + 0x74) & 3;
  uVar4 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,7,uVar7,0,0,1,1);
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  sVar2 = *(short *)(iVar3 + 0x82);
  iVar5 = r_lld_adv_ext_pkt_prepare(param_1,uVar4,7,uVar7,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  if (sVar2 != 0) {
    r_assert_err(0,"lld_adv.c",0x636);
  }
  uVar10 = (uint)*(byte *)(iVar3 + 0x91) << 10;
  if ((uVar10 & 0x30000) != 0) {
    r_assert_err(0,"lld_adv.c",0x635);
  }
  iVar9 = param_1 * 0x5a;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar7 = *(ushort *)(iVar5 + iVar9 + 0x26);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar9 + 0x26) = uVar7 & 0x3ff | (ushort)uVar10;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar7 = *(ushort *)(iVar5 + iVar9 + 4);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar9 + 4) = uVar7 & 0xffcf | 0x10;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar9 + 0x34 + iVar5) = (short)uVar4 * 0xe + 0x1400;
  cVar6 = *(char *)(iVar3 + 0x90);
  if (cVar6 == '\x03') {
    cVar6 = '\x02';
  }
  iVar5 = r_co_ble_pkt_dur_in_us(0x22,cVar6);
  bVar1 = *(byte *)(iVar3 + 0x87);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5 + 0x96;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar8 = (ushort)bVar1 * 9 + 2 & 0xff;
  uVar7 = *(ushort *)(iVar5 + uVar4 * 0xe);
  iVar5 = r_emi_get_mem_addr_by_offset();
  *(ushort *)(iVar5 + uVar4 * 0xe) = uVar8 * 0xe + 0x1400 | uVar7 & 0x8000;
  r_lld_adv_ext_pkt_prepare(param_1,uVar8,8,0,1,1,0,0);
  *(undefined1 *)(iVar3 + 0x92) = 3;
  return;
}

