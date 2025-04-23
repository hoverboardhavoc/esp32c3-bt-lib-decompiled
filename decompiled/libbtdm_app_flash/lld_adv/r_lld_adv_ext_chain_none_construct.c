/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_none_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_none_construct(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  int iVar10;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  cVar7 = *(char *)(iVar4 + 0x87) * '\t';
  uVar2 = *(ushort *)(iVar4 + 0x74);
  uVar9 = 0;
  bVar8 = cVar7 + 1;
  uVar5 = (uint)bVar8;
  if (((uVar2 & 3) == 0) &&
     (uVar9 = uVar2 >> 2 & (ushort)(*(short *)(iVar4 + 0x82) == 0), *(short *)(iVar4 + 0x82) == 0))
  {
    iVar6 = r_sdk_config_get_opts_ext();
    uVar9 = uVar9 | *(char *)(iVar6 + 0x1a) != '\0';
  }
  if (((*(short *)(iVar4 + 0x82) == 0) && (*(int *)(iVar4 + 0x68) == 0)) && (uVar9 == 0)) {
    iVar6 = r_lld_adv_ext_pkt_prepare
                      (param_1,7,*(ushort *)(iVar4 + 0x74) >> 5 & 1 ^ 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0,0);
    bVar8 = *(byte *)(iVar4 + 0x87);
    *(undefined1 *)(iVar4 + 0x95) = 0;
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    cVar7 = '\x01';
    *(undefined2 *)((uint)bVar8 * 0x7e + 0x12 + iVar6) = 0;
  }
  else {
    iVar6 = r_lld_adv_ext_pkt_prepare(param_1,cVar7,7,0,0,1);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    sVar3 = *(short *)(iVar4 + 0x82);
    iVar6 = r_lld_adv_ext_pkt_prepare
                      (param_1,uVar5,7,uVar2 & 3,*(ushort *)(iVar4 + 0x74) >> 5 & 1 ^ 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0);
    bVar1 = *(byte *)(iVar4 + 0x91);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    if ((bVar1 & 0xc0) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar10 = param_1 * 0x5a;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar6 + iVar10 + 0x26);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar10 + 0x26) = uVar2 & 0x3ff | (ushort)bVar1 << 10;
    bVar1 = *(byte *)(iVar4 + 0x90);
    if ((bVar1 & 0xfc) != 0) {
      r_assert_err(0,0x10000,0x1bf);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar6 + iVar10 + 4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar10 + 4) = uVar2 & 0xffcf | (ushort)bVar1 << 4;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar10 + 0x34 + iVar6) = (ushort)bVar8 * 0xe + 0x1400;
    cVar7 = '\x01';
    while (sVar3 != 0) {
      iVar6 = uVar5 * 0xe;
      bVar8 = *(char *)(iVar4 + 0x87) * '\t' + cVar7 + '\x01';
      uVar5 = (uint)bVar8;
      iVar10 = r_lld_adv_ext_pkt_prepare(param_1,uVar5,7,0,0,0,1,0);
      *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar10;
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = *(ushort *)(iVar10 + iVar6);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar10) = (ushort)bVar8 * 0xe + 0x1400 | uVar2 & 0x8000;
      cVar7 = cVar7 + '\x01';
    }
  }
  *(char *)(iVar4 + 0x92) = cVar7 + '\x01';
  return;
}

