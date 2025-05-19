/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_scannable_construct_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_scannable_construct_hack(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar3 + 0x74);
  uVar7 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar4 = r_lld_adv_ext_pkt_prepare(param_1,7,0,0,1,1);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar4;
  iVar4 = r_lld_adv_ext_pkt_prepare
                    (param_1,uVar7,7,uVar1 & 3,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar4;
  uVar8 = (uint)*(byte *)(iVar3 + 0x91) << 10;
  if ((uVar8 & 0x30000) != 0) {
    r_assert_err(0,0x10000,0x635);
  }
  iVar4 = param_1 * 0x5a;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar5 + iVar4 + 0x26);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar4 + 0x26) = uVar1 & 0x3ff | (ushort)uVar8;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar5 + iVar4 + 4);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar4 + 4) = uVar1 & 0xffcf | 0x10;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar4 + 0x34 + iVar5) = (short)((uVar7 * 0xe + 0x1400) * 0x10000 >> 0x10);
  cVar9 = *(char *)(iVar3 + 0x90);
  if (cVar9 == '\x03') {
    cVar9 = '\x02';
  }
  iVar4 = r_co_ble_pkt_dur_in_us(0xc,cVar9);
  bVar6 = *(byte *)(iVar3 + 0x87);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar4 + 0x96;
  sVar2 = *(short *)(iVar3 + 0x84);
  cVar9 = '\x02';
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar8 = (uint)bVar6 * 9 + 2 & 0xff;
  uVar1 = *(ushort *)(iVar4 + uVar7 * 0xe);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(uVar7 * 0xe + iVar4) = (short)uVar8 * 0xe + 0x1400U | uVar1 & 0x8000;
  iVar4 = r_lld_adv_ext_pkt_prepare(param_1,uVar8,7,0,1,0,0,0);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar4;
  while (cVar9 = cVar9 + '\x01', sVar2 != 0) {
    iVar4 = uVar8 * 0xe;
    bVar6 = *(char *)(iVar3 + 0x87) * '\t' + cVar9;
    uVar8 = (uint)bVar6;
    iVar5 = r_lld_adv_ext_pkt_prepare(param_1,uVar8,7,0,0,0,0,0);
    *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar5 + iVar4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar5) = (ushort)bVar6 * 0xe + 0x1400 | uVar1 & 0x8000;
  }
  *(char *)(iVar3 + 0x92) = cVar9;
  return;
}

