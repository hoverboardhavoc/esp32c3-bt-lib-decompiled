/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_frm_isr_hack(uint param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char cVar10;
  code *pcVar11;
  
  if (periodic_adv_data_need_to_set[param_1] != '\0') {
    *(undefined4 *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x24) = 0;
    (**(code **)(_r_ip_funcs_p + 0x2d4))(0,0,1,1,*(code **)(_r_ip_funcs_p + 0x2d4));
    periodic_adv_data_need_to_set[param_1] = '\0';
  }
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x848))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x848));
  if (iVar5 != 0) {
    return;
  }
  iVar5 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar5 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_per_adv.c",0x43e,*(code **)(_r_plf_funcs_p + 8));
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar5,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar5 + 0x53) == '\x02') {
      puVar6 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x208,0,0xff,2,*(code **)(_r_modules_funcs_p + 200));
      uVar1 = *(undefined1 *)(iVar5 + 0x52);
      puVar6[1] = 0;
      *puVar6 = uVar1;
      (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x2cc);
      uVar9 = param_1;
    }
    else {
      bVar2 = *(byte *)(iVar5 + 0x52);
      if (*(short *)(iVar5 + 0x24) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x2d4))
                  (param_1,*(undefined1 *)(iVar5 + 0x26),1,1,*(code **)(_r_ip_funcs_p + 0x2d4));
        *(undefined2 *)(iVar5 + 0x24) = 0;
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = ((uint)bVar2 * 9 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar7 + iVar4);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = _r_plf_funcs_p;
      *(ushort *)(iVar8 + iVar4) = uVar3 & 0x7fff;
      iVar7 = (**(code **)(iVar7 + 0xbc))(0x1400,*(code **)(iVar7 + 0xbc));
      if ((int)((uint)*(ushort *)(iVar7 + iVar4 + 6) << 0x13) < 0) {
        bVar2 = *(byte *)(iVar5 + 0x52);
        uVar9 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
        *(char *)(iVar5 + 0x57) = (char)uVar9;
        if ((uVar9 & 0xffffffc0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x2ea,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar7 + iVar4 + 8);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + 8 + iVar7) = uVar3 & 0xffc0 | (ushort)uVar9;
        uVar9 = (uint)*(byte *)(iVar5 + 0x57) << 10;
        if ((uVar9 & 0x30000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar4 = (uint)bVar2 * 0x5a + 0x26;
        uVar3 = *(ushort *)(iVar7 + iVar4);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar7) = uVar3 & 0x3ff | (ushort)uVar9;
        uVar9 = 0;
        while( true ) {
          bVar2 = *(byte *)(iVar5 + 0x52);
          uVar9 = uVar9 + 1 & 0xff;
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar7 = ((uint)bVar2 * 9 + uVar9 & 0xff) * 0xe;
          uVar3 = *(ushort *)(iVar4 + iVar7);
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar4 + iVar7) = uVar3 & 0x7fff;
          if (uVar9 == *(byte *)(iVar5 + 0x58) - 1) break;
          bVar2 = *(byte *)(iVar5 + 0x57);
          if ((bVar2 & 0xc0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x2ea,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar3 = *(ushort *)(iVar4 + iVar7 + 8);
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar7 + 8 + iVar4) = uVar3 & 0xffc0 | (ushort)bVar2;
        }
      }
      bVar2 = DAT_0001301b;
      cVar10 = DAT_0001301a;
      if (param_3 != 0) {
        cVar10 = *(char *)(iVar5 + 0x16) + DAT_0001301b;
      }
      *(char *)(iVar5 + 0x16) = cVar10;
      *(ushort *)(iVar5 + 0x14) = bVar2 & 0xf | 0x2000;
      uVar9 = (uint)*(byte *)(iVar5 + 0x52);
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x300);
    }
    (*pcVar11)(uVar9,pcVar11);
  }
                    /* WARNING: Could not recover jumptable at 0x000114fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x848))(0,param_1,param_2,param_3);
  return;
}

