/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  
  if (param_1 == 0) goto _L533;
  iVar10 = (*(byte *)(param_1 + 0x8e) + 0x18) * 2;
  if ((((&DAT_000149bd)[iVar10] == '\0') || (*(char *)(param_1 + 0x46) != (&DAT_000149bd)[iVar10]))
     || (uVar13 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff,
        0x7ffe < (uVar13 - *(ushort *)(param_1 + 0x44) & 0xffff))) goto _L533;
  bVar1 = (&DAT_000149bc)[iVar10];
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar12 = (uint)bVar1 * 0xe;
  if (*(short *)(iVar6 + iVar12) < 0) goto _L533;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar3 = *(short *)(iVar6 + iVar12 + 4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar4 = *(ushort *)(iVar12 + 2 + iVar6);
  uVar5 = (ushort)(byte)(&DAT_000149bd)[iVar10];
  if (uVar5 == 1) {
    uVar5 = 10;
_L549:
    cVar11 = '\0';
  }
  else if (uVar5 == 2) {
    uVar5 = 6;
    cVar11 = '\x01';
  }
  else {
    cVar11 = '\x18';
    if (uVar5 != 3) {
      r_assert_param(*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x560);
      uVar5 = 0;
      goto _L549;
    }
  }
  if (((sVar3 == 0) || ((uVar4 & 3) != 3)) ||
     (pcVar7 = (char *)r_emi_get_mem_addr_by_offset(sVar3), *pcVar7 != cVar11)) {
    if (0 < _g_bt_plf_log_level) {
      puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3);
      uVar2 = *puVar8;
      puVar9 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar5);
      ets_printf("llcp check: %u %u %u %u %u\n",uVar13,uVar2,*puVar9,*(undefined1 *)(param_1 + 0x46)
                 ,*(undefined2 *)(param_1 + 0x44));
    }
    *(undefined2 *)(&DAT_000149bc + (*(byte *)(param_1 + 0x8e) + 0x18) * 2) = 0;
  }
  else {
    iVar10 = *(ushort *)(param_1 + 0x72) + 9 + uVar13;
    iVar6 = iVar10 * 0x10000;
    puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar5);
    *puVar8 = (char)((uint)iVar6 >> 0x10);
    puVar8[1] = (char)((uint)iVar10 >> 8);
    *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
  }
_L533:
  r_lld_con_evt_start_cbk(param_1);
  iVar10 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar10 + 0x19) == '\x02') {
    r_lld_cca_con_evt_start_handle(param_1);
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

