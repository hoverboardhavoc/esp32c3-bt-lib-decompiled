/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc.o -> r_llc_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llc_start_eco(uint param_1,undefined4 *param_2,void *param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  void *__src;
  int iVar4;
  ushort *puVar5;
  ushort uVar6;
  undefined2 uVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined2 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  char cStack_34;
  byte bStack_33;
  undefined2 uStack_32;
  
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (param_1 < *(byte *)(iVar4 + 0xd)) {
    puVar5 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
    *puVar5 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar5;
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar9 = 9;
  if (param_1 < *(byte *)(iVar4 + 0xd)) {
    piVar8 = (int *)(&llc_env + param_1 * 4);
    if (*piVar8 == 0) {
      uVar9 = 7;
      puVar3 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 0x120))
                         (0x4c,*(code **)(_r_modules_funcs_p + 0x120));
      *piVar8 = (int)puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)(_r_modules_funcs_p + 0x154))
                  (param_1 << 8 | 1,0,*(code **)(_r_modules_funcs_p + 0x154));
        (**(code **)(_r_modules_funcs_p + 0x2c))(puVar3 + 10,*(code **)(_r_modules_funcs_p + 0x2c));
        *(undefined1 *)((int)puVar3 + 0x45) = 0;
        *(undefined2 *)((int)puVar3 + 0x46) = 0;
        *(byte *)(puVar3 + 0x11) = *(byte *)(puVar3 + 0x11) & 0xf0;
        *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)((int)param_2 + 10);
        uVar7 = *(undefined2 *)(param_2 + 3);
        *(undefined2 *)((int)puVar3 + 0x42) = 0;
        *(undefined1 *)((int)puVar3 + 0x49) = 0;
        *(undefined2 *)(puVar3 + 4) = uVar7;
        *(undefined2 *)((int)puVar3 + 0x12) = *(undefined2 *)((int)param_2 + 0xe);
        memcpy(puVar3 + 2,param_2 + 4,5);
        __src = (void *)(**(code **)(_r_ip_funcs_p + 0x4e4))(*(code **)(_r_ip_funcs_p + 0x4e4));
        memcpy(puVar3 + 0xc,__src,8);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        if ((param_1 < *(byte *)(iVar4 + 0xd)) && (iVar4 = *piVar8, iVar4 != 0)) {
          *(byte *)(iVar4 + 0x30) = *(byte *)(iVar4 + 0x30) & 0xfb;
        }
        *(undefined2 *)(puVar3 + 5) = 0x1b;
        bVar1 = *(byte *)(param_2 + 9);
        cVar2 = (&co_rate_to_phy)[bVar1];
        if (cVar2 == '\x03') {
          uVar7 = 0xa90;
        }
        else {
          uVar7 = 0x148;
        }
        *(undefined2 *)(puVar3 + 6) = uVar7;
        *(undefined2 *)((int)puVar3 + 0x1a) = uVar7;
        *(undefined2 *)((int)puVar3 + 0x1e) = 0x207;
        *(undefined2 *)((int)puVar3 + 0x16) = 0x1b;
        *(char *)(puVar3 + 7) = cVar2;
        *(char *)((int)puVar3 + 0x1d) = cVar2;
        memcpy(puVar3 + 8,param_3,8);
        if (cVar2 == '\x03') {
          uVar6 = *(ushort *)((int)puVar3 + 0x22);
          if (uVar6 < 0xa90) {
            uVar6 = 0xa90;
          }
          *(ushort *)((int)puVar3 + 0x22) = uVar6;
        }
        cStack_34 = *(char *)((int)param_2 + 0x25);
        *puVar3 = 0;
        puVar3[1] = 0;
        *(ushort *)((int)puVar3 + 0x42) =
             (ushort)(cStack_34 == '\0') | *(ushort *)((int)puVar3 + 0x42) & 0xfffe;
        uStack_58 = *param_2;
        uStack_54 = *(undefined2 *)(param_2 + 1);
        uStack_52 = *(undefined1 *)((int)param_2 + 6);
        uStack_51 = *(undefined1 *)((int)param_2 + 7);
        uStack_50 = param_2[2];
        uStack_4c = param_2[3];
        uStack_48 = param_2[4];
        uStack_44 = *(undefined1 *)(param_2 + 5);
        uStack_43 = *(undefined1 *)((int)param_2 + 0x15);
        uStack_42 = *(undefined1 *)((int)param_2 + 0x16);
        uStack_40 = *(undefined2 *)(param_2 + 6);
        uStack_3c = param_2[7];
        uStack_38 = param_2[8];
        uStack_32 = *(undefined2 *)((int)param_2 + 0x26);
        bStack_33 = bVar1;
        uVar9 = (**(code **)(_r_ip_funcs_p + 0x3b0))
                          (param_1,&uStack_58,*(code **)(_r_ip_funcs_p + 0x3b0));
        if ((DAT_00011058 != '\0') &&
           (iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
           *(char *)(iVar4 + 0x20) != '\0')) {
          (**(code **)(_r_ip_funcs_p + 0x614))(param_1,3000,*(code **)(_r_ip_funcs_p + 0x614));
        }
        if ((DAT_00011059 != '\0') &&
           (iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
           *(char *)(iVar4 + 0x18) != '\0')) {
          (**(code **)(_r_ip_funcs_p + 0x658))(param_1,*(code **)(_r_ip_funcs_p + 0x658));
        }
        if (DAT_00011057 != '\0') {
          (**(code **)(_r_ip_funcs_p + 0x5c8))(param_1,*(code **)(_r_ip_funcs_p + 0x5c8));
        }
      }
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"llc.c",0x11e,*(code **)(_r_plf_funcs_p + 0xc));
      uVar9 = 0xff;
    }
  }
  return uVar9;
}

