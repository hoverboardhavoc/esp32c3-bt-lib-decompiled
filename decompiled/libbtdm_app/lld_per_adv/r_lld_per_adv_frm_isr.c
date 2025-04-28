/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_frm_isr(uint param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  code *pcVar10;
  
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x848))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x848));
  if (iVar5 != 0) {
    return;
  }
  iVar5 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar5 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x43e,*(code **)(_r_plf_funcs_p + 8));
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
      pcVar10 = *(code **)(_r_ip_funcs_p + 0x2cc);
      uVar8 = param_1;
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
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar7 + iVar4) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      iVar7 = (*pcVar10)(0x1400,pcVar10);
      if ((*(ushort *)(iVar4 + 6 + iVar7) >> 0xc & 1) != 0) {
        bVar2 = *(byte *)(iVar5 + 0x52);
        uVar8 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
        *(char *)(iVar5 + 0x57) = (char)uVar8;
        if ((uVar8 & 0xffffffc0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2ea,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar7 + iVar4 + 8);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar7 + iVar4 + 8) = uVar3 & 0xffc0 | (ushort)uVar8;
        uVar8 = (uint)*(byte *)(iVar5 + 0x57) << 10;
        if ((uVar8 & 0x30000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x635,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar7 = (uint)bVar2 * 0x5a + 0x26;
        uVar3 = *(ushort *)(iVar4 + iVar7);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar7) = uVar3 & 0x3ff | (ushort)uVar8;
        uVar8 = 0;
        while( true ) {
          bVar2 = *(byte *)(iVar5 + 0x52);
          uVar8 = uVar8 + 1 & 0xff;
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar4 = ((uint)bVar2 * 9 + uVar8 & 0xff) * 0xe;
          uVar3 = *(ushort *)(iVar7 + iVar4);
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar7 + iVar4) = uVar3 & 0x7fff;
          if (uVar8 == *(byte *)(iVar5 + 0x58) - 1) break;
          bVar2 = *(byte *)(iVar5 + 0x57);
          if ((bVar2 & 0xc0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2ea,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar3 = *(ushort *)(iVar7 + iVar4 + 8);
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar7 + iVar4 + 8) = uVar3 & 0xffc0 | (ushort)bVar2;
        }
      }
      bVar2 = DAT_0001301b;
      cVar9 = DAT_0001301a;
      if (param_3 != 0) {
        cVar9 = *(char *)(iVar5 + 0x16) + DAT_0001301b;
      }
      *(char *)(iVar5 + 0x16) = cVar9;
      *(ushort *)(iVar5 + 0x14) = bVar2 & 0xf | 0x2000;
      uVar8 = (uint)*(byte *)(iVar5 + 0x52);
      pcVar10 = *(code **)(_r_ip_funcs_p + 0x300);
    }
    (*pcVar10)(uVar8,pcVar10);
  }
                    /* WARNING: Could not recover jumptable at 0x0001150e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x848))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x848));
  return;
}

