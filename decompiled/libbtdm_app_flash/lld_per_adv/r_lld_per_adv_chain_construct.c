/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_chain_construct(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  char cVar8;
  short sStack_46;
  undefined2 uStack_44;
  short sStack_42;
  
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uVar3 = (uint)*(byte *)(iVar2 + 0x52) * 9 & 0xff;
  sStack_46 = (ushort)*(byte *)(iVar2 + 0x52) * 0x4b + 0x2000;
  uVar4 = r_lld_ch_idx_get_hack();
  uStack_44 = *(undefined2 *)(iVar2 + 0x4e);
  *(undefined2 *)(iVar2 + 0x4a) = 0;
  *(undefined1 *)(iVar2 + 0x57) = uVar4;
  sStack_42 = *(short *)(iVar2 + 0x50);
  *(undefined4 *)(iVar2 + 0x44) = 0;
  iVar5 = r_lld_per_adv_ext_pkt_prepare
                    (param_1,uVar3,7,0,*(uint *)(iVar2 + 0x48) >> 6 & 1,0,&sStack_46,&uStack_44);
  bVar6 = *(byte *)(iVar2 + 0x57);
  *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + iVar5;
  if ((bVar6 & 0xc0) != 0) {
    r_assert_err(0,0x10000,0x635);
  }
  iVar7 = param_1 * 0x5a;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar5 + iVar7 + 0x26);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar7 + 0x26) = uVar1 & 0x3ff | (ushort)bVar6 << 10;
  bVar6 = *(byte *)(iVar2 + 0x55);
  if ((bVar6 & 0xfc) != 0) {
    r_assert_err(0,0x10000,0x1bf);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar5 + iVar7 + 4);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar7 + 4) = uVar1 & 0xffcf | (ushort)bVar6 << 4;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar7 + 0x34 + iVar5) = (short)uVar3 * 0xe + 0x1400;
  cVar8 = '\0';
  while( true ) {
    cVar8 = cVar8 + '\x01';
    if (sStack_42 == 0) break;
    iVar5 = uVar3 * 0xe;
    bVar6 = *(char *)(iVar2 + 0x52) * '\t' + cVar8;
    uVar3 = (uint)bVar6;
    iVar7 = r_lld_per_adv_ext_pkt_prepare
                      (param_1,uVar3,7,0,*(uint *)(iVar2 + 0x48) >> 6 & 1,0,&sStack_46,&uStack_44);
    *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + iVar7;
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar7 + iVar5);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = (ushort)bVar6 * 0xe + 0x1400 | uVar1 & 0x8000;
  }
  uVar3 = (uint)_sdk_cfg_priv_opts;
  *(char *)(iVar2 + 0x58) = cVar8;
  uVar3 = *(int *)(iVar2 + 0x44) * 2 + uVar3;
  if (uVar3 < 0x272) {
    uVar3 = 0x272;
  }
  *(uint *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x10) = uVar3;
  return;
}

