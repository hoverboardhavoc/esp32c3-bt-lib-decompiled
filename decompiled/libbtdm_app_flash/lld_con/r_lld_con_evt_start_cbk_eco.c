/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  char cVar12;
  uint uVar13;
  
  if (param_1 == 0) goto _L561;
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x40430009,CONCAT11(*(undefined1 *)(param_1 + 0x16),*(undefined1 *)(param_1 + 0x8e)),
               *(undefined4 *)(param_1 + 4));
  }
  iVar7 = (*(byte *)(param_1 + 0x8e) + 0x18) * 2;
  if (((&DAT_0001503d)[iVar7] == '\0') || (*(char *)(param_1 + 0x46) != (&DAT_0001503d)[iVar7]))
  goto _L561;
  uVar13 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
  bVar1 = (&DAT_0001503c)[iVar7];
  if (0x7ffe < (uVar13 - *(ushort *)(param_1 + 0x44) & 0xffff)) goto _L561;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = (uint)bVar1 * 0xe;
  if (*(short *)(iVar8 + iVar6) < 0) goto _L561;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar3 = *(short *)(iVar6 + 4 + iVar8);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar4 = *(ushort *)(iVar6 + 2 + iVar8);
  uVar5 = (ushort)(byte)(&DAT_0001503d)[iVar7];
  if (uVar5 == 1) {
    uVar5 = 10;
_L580:
    cVar12 = '\0';
  }
  else if (uVar5 == 2) {
    uVar5 = 6;
    cVar12 = '\x01';
  }
  else {
    cVar12 = '\x18';
    if (uVar5 != 3) {
      r_assert_param(*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x56f);
      uVar5 = 0;
      goto _L580;
    }
  }
  if (((sVar3 == 0) || ((uVar4 & 3) != 3)) ||
     (pcVar9 = (char *)r_emi_get_mem_addr_by_offset(sVar3), *pcVar9 != cVar12)) {
    if (0 < _g_bt_plf_log_level) {
      puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3);
      uVar2 = *puVar10;
      puVar11 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar5);
      ets_printf("llcp check: %u %u %u %u %u\n",uVar13,uVar2,*puVar11,
                 *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
    }
    r_lld_con_llcp_ind_info_clear(*(undefined1 *)(param_1 + 0x8e));
  }
  else {
    iVar7 = *(ushort *)(param_1 + 0x72) + 9 + uVar13;
    iVar6 = iVar7 * 0x10000;
    puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar5);
    *puVar10 = (char)((uint)iVar6 >> 0x10);
    puVar10[1] = (char)((uint)iVar7 >> 8);
    *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
  }
_L561:
  r_lld_con_evt_start_cbk(param_1);
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x19) == '\x02') {
    r_lld_cca_con_evt_start_handle(param_1);
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

